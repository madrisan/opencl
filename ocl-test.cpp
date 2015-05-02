#define __CL_ENABLE_EXCEPTIONS	
#include <CL/cl.hpp>

#include <iostream>

int main () {
    try {
        std::vector<cl::Platform> platformList;
        cl::Platform::get (&platformList);
        if (platformList.size () == 0) {
            std::cout << "No OpenCL platforms detected" << std::endl;
            return -1;
        }

        for (auto p : platformList) {
            std::string platformVendor;
            p.getInfo(CL_PLATFORM_NAME, &platformVendor);
            std::cout << platformVendor << std::endl;
        }
    }
    catch (cl::Error err) {
        std::cerr << "ERROR: " << err.what () << "(" << err.err () << ")"
                  << std::endl;
    }

    return 0;
}
