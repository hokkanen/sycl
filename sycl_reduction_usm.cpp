#include <sycl/sycl.hpp>

int main(int argc, char *argv[]) {
  sycl::queue q;
  unsigned n = 10;

  // Buffers with just 1 element to get the reduction results
  int* sum = sycl::malloc_shared<int>(1, q);
  *sum = 0;

  q.submit([&](sycl::handler &cgh) {
    // Create temporary objects describing variables with reduction semantics
    auto sum_reduction = sycl::reduction(sum, sycl::plus<int>());

    // A reference to the reducer is passed to the lambda
    cgh.parallel_for(sycl::range<1>{n}, sum_reduction,
                      [=](sycl::id<1> idx, auto &reducer) { reducer.combine(idx[0]); });
  }).wait();

  // Print results
  printf("sum = %d\n", *sum);
}