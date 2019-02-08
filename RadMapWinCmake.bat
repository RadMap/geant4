SET mypath=%~dp0
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DGEANT4_BUILD_CXXSTD="11" -DGEANT4_USE_OPENGL_WIN32=ON -DXERCESC_LIBRARY="D:/xerces-c/installation/lib/xerces-c_3.lib" -DXERCESC_INCLUDE_DIR="D:/xerces-c/installation/include" -DXERCESC_ROOT_DIR="D:/xerces-c/installation" -DGEANT4_USE_GDML=ON -DGEANT4_BUILD_MSVC_MP=ON -DGEANT4_INSTALL_DATA=ON -DCMAKE_INSTALL_PREFIX="%mypath:~0,-1%/install" "%mypath%"
cmake --build . --config Release --target install
cmake -DXERCESC_LIBRARY="D:/xerces-c/installation/lib/xerces-c_3D.lib"
cmake --build . --config Debug --target install