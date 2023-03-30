## Notes for compiling and running SYCL code on Intel CPUs

### 1. Install Intel OneApi basekit

### 2. Set up environment by running
```
source /opt/intel/oneapi/setvars.sh
```

This sets up paths and runtime environment for OpenCL execution. For example, the following paths are added. The compiler
```
/opt/intel/oneapi/compiler/latest/linux/bin/dpcpp
```
the includes in 
```
/opt/intel/oneapi/compiler/latest/linux/include/sycl/
```
and libs in 
```
/opt/intel/oneapi/compiler/latest/linux/lib/
``` 
and 
```
/opt/intel/oneapi/compiler/latest/linux/compiler/lib/intel64_lin/
```

### 3. Clone repo
```
git clone https://github.com/hokkanen/sycl.git
```

### 4. Compile examples with 
```
dpcpp sycl_async_usm.cpp
```

### 5. Run examples with
```
./a.out
```
