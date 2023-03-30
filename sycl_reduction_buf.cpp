#include <sycl/sycl.hpp>

int main(int argc, char *argv[]) {
  sycl::queue q;
  unsigned n = 10;

  // Initialize sum
  int sum = 0;
  {
    // Create a buffer for sum to get the reduction results
    sycl::buffer<int> sum_buf{&sum, 1};
  
    // Submit a SYCL kernel into a queue
    q.submit([&](sycl::handler &cgh) {
      // Create temporary object describing variables with reduction semantics
      auto sum_reduction = sycl::reduction(sum_buf, cgh, sycl::plus<>());
  
      // A reference to the reducer is passed to the lambda
      cgh.parallel_for(sycl::range<1>{n}, sum_reduction,
                      [=](sycl::id<1> idx, auto &reducer) { reducer.combine(idx[0]); });
    }).wait();
    // The contents of sum_buf are copied back to sum by the destructor of sum_buf
  }
  // Print results
  printf("sum = %d\n", sum);
}
