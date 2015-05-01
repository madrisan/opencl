#include <iostream>
#include <CL/cl.h>

using namespace std;

#define dieOnError(clretcode, errmsg) do {     \
    if (clretcode != CL_SUCCESS) {             \
        cerr << "ERROR: " << errmsg << endl;   \
        return 1;                              \
    }                                          \
} while(0)

int
main ()
{
  // create an OpenCL context
  cl_uint numPlatforms = 0;

  cl_int clerr = clGetPlatformIDs (0, NULL, &numPlatforms);
  dieOnError (clerr, "Failed to run clGetPlatformIDs()");
  cout << "Number of available platforms: " << numPlatforms << endl;

  cl_platform_id *platforms = new cl_platform_id[numPlatforms];
  clerr = clGetPlatformIDs (numPlatforms, platforms, NULL);
  dieOnError (clerr, "Failed to run clGetPlatformIDs()");

  for (cl_uint i = 0; i < numPlatforms; i++)
    {
      size_t platformNameLength;
      clerr = clGetPlatformInfo (platforms[i],
				 CL_PLATFORM_NAME,
				 0, NULL, &platformNameLength);
      dieOnError (clerr, "Failed to run clGetPlatformInfo");
      char *platformName = new char[platformNameLength];
      clerr = clGetPlatformInfo (platforms[i],
				 CL_PLATFORM_NAME,
				 platformNameLength, platformName, NULL);
      dieOnError (clerr, "Failed to run clGetPlatformInfo");

      cout << (i + 1) << " : " << platformName << endl;

      delete platformName;
    }

  delete[] platforms;
 
  return 0;
}
