<h1  align="center" id="ZIPManagement_PhysFS">Assets ZIP management with PhysFS</h1>

<p>Welcome to the webpage of how to implement <a href="https://github.com/AaronGCProg/ZIPManagement_PhysFS">Assets ZIP management with PhysicsFS</a></p>

<h2  align="center" id="physfs">What is PhysicsFS?</h2>

<p align="justify"><b>Explanation from <a href="https://icculus.org/physfs/">icculus.org</a></b>: PhysicsFS is a library to provide abstract access to various archives. It is intended for use in video games, and the design was somewhat inspired by Quake 3's file subsystem. The programmer defines a "write directory" on the physical filesystem. No file writing done through the PhysicsFS API can leave that write directory, for security. For example, an embedded scripting language cannot write outside of this path if it uses PhysFS for all of its I/O, which means that untrusted scripts can run more safely. Symbolic links can be disabled as well, for added safety. For file reading, the programmer lists directories and archives that form a "search path". Once the search path is defined, it becomes a single, transparent hierarchical filesystem. This makes for easy access to ZIP files in the same way as you access a file directly on the disk, and it makes it easy to ship a new archive that will override a previous archive on a per-file basis. Finally, PhysicsFS gives you platform-abstracted means to determine if CD-ROMs are available, the user's home directory, where in the real filesystem your program is running, etc.</p> 

<p align="justify">In summary, PhysicsFS it's a portable, flexible file i/o abstraction. This API gives you access to a system file system in ways superior to the stdio or system i/o calls. The <b>main benefits</b> highlighted by the API developers are that it is <b>portable</b>, more <b>secure</b> because no file acces is permitted outside the specified dirs, and <b>flexible</b> because archives can be used transparently as directory structures.</p>



<h2  align="center" id="howimplement">How can I implement it?</h2>

<p align="justify">If you want to use Visual Studio, nmake, or the Platform SDK, you will need <a href="https://cmake.org/download/">CMake.</a> Let's take a little break to explain what is CMake about. </p>


<h3  align="center" id="cmake">CMake</h3>

<p align="justify">CMake is a multiplatform code generation or automation tool. The name is an abbreviation for "cross platform brand"; Beyond the use of "make" in the name, CMake is a separate, higher-level suite that the system makes common to Unix, being similar to automated tools.</p>

<p align="justify">It is an extensible, open-source system that manages the build process in an operating system and in a compiler-independent manner. Unlike many cross-platform systems, CMake is designed to be used in conjunction with the native build environment. Simple configuration files placed in each source directory (called CMakeLists.txt files) are used to generate standard build files (e.g., makefiles on Unix and projects/workspaces in Windows MSVC) which are used in the usual way. CMake can generate a native build environment that will compile source code, create libraries, generate wrappers and build executables in arbitrary combinations.</p>

<p align="justify">We will need CMake to carry out a PhysFS build, obtaining the libraries and .dll that we need to implement it in our project.</p>



<h3  align="center" id="cmake">Steps to obtain PhysFS .dll</h3>

1. Download PhysicsFS ZIP from icculus.org. If you want to download the file directly, <a href="https://icculus.org/physfs/downloads/physfs-3.0.2.tar.bz2">click here</a>.

2. Download CMake. I recommend the version with interface since it is more intuitive and is the one that I will explain next. If you want to download it directly, <a href="https://github.com/Kitware/CMake/releases/download/v3.17.0/cmake-3.17.0-win64-x64.msi">click here</a>.

3. Install CMake and open "CMake (cmake-gui)" executable
