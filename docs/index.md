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



<h3  align="center" id="cmake">Steps to obtain PhysFS .dll and .lib</h3>

<b>Remember that it is not necessary to follow all these steps if you are not interested! You have the .dll, .lib and a sample of how everything is integrated into the Solution. You have complete freedom to take what you want from there!</b>

1. Download PhysicsFS ZIP from icculus.org. If you want to download the file directly, <a href="https://icculus.org/physfs/downloads/physfs-3.0.2.tar.bz2">click here</a>.

<img src="https://raw.githubusercontent.com/AaronGCProg/ZIPManagement_PhysFS/master/docs/imagesWeb/dll_steps/step1.JPG" class="center">

2. Download CMake. I recommend the version with interface since it is more intuitive and is the one that I will explain next. If you want to download it directly, <a href="https://github.com/Kitware/CMake/releases/download/v3.17.0/cmake-3.17.0-win64-x64.msi">click here</a>.

<img src="https://raw.githubusercontent.com/AaronGCProg/ZIPManagement_PhysFS/master/docs/imagesWeb/dll_steps/step2.JPG" class="center">

3. Install CMake and open "CMake (cmake-gui)" executable. Check where CMakeLists.txt is in the downloaded PhysicsFS folder 
(In this case it is the base folder) and get this path to <b>the source code</b> field. To <b>build the binaries</b> you can create any empty folder.

<img src="https://raw.githubusercontent.com/AaronGCProg/ZIPManagement_PhysFS/master/docs/imagesWeb/dll_steps/step3.JPG" class="center">

4. Click configure and set-up the following options with your Visual Studio version and if you will use x64 or x86. 

<img src="https://raw.githubusercontent.com/AaronGCProg/ZIPManagement_PhysFS/master/docs/imagesWeb/dll_steps/step5.JPG" class="center">

5. Once we have finished the previous window, the following options will be generated. We must discard them all except PHYSFS_BUILD_SHARED and in this case, PHYSFS_ARCHIVE_ZIP. Then, click Generate.

<img src="https://raw.githubusercontent.com/AaronGCProg/ZIPManagement_PhysFS/master/docs/imagesWeb/dll_steps/step6.JPG" class="center">

6. This files will be generated. We will need to run the file PhysicsFS.sln and then prepare a build in Release and Win32.

<img src="https://raw.githubusercontent.com/AaronGCProg/ZIPManagement_PhysFS/master/docs/imagesWeb/dll_steps/step7.JPG" class="center">
<img src="https://raw.githubusercontent.com/AaronGCProg/ZIPManagement_PhysFS/master/docs/imagesWeb/dll_steps/step7_2.JPG" class="center">

7. In the generated Release folder we will have everything you want. You will find the physfs.h in the following path of the folder you originally download.

<img src="https://raw.githubusercontent.com/AaronGCProg/ZIPManagement_PhysFS/master/docs/imagesWeb/dll_steps/step8.JPG" class="center">
<img src="https://raw.githubusercontent.com/AaronGCProg/ZIPManagement_PhysFS/master/docs/imagesWeb/dll_steps/step8_2.JPG" class="center">

<h2  align="center" id="exercises">Exercises</h2>

TODO 1:


<h2  align="center" id="bibliography">Bibliography</h2>

<ul>
  <li> PhysicsFS : <a href="https://icculus.org/physfs/">https://icculus.org/physfs/</a></li>
  <li> PhysFS Documentation : <a href="https://icculus.org/physfs/docs/html/physfs_8h.html">https://icculus.org/physfs/docs/html/physfs_8h.html</a></li>
  <li> Pugui Loading from Memory : <a href="https://pugixml.org/docs/manual.html#loading.memory">https://pugixml.org/docs/manual.html#loading.memory/</a></li>  
  <li> CMake Building : <a href="https://preshing.com/20170511/how-to-build-a-cmake-based-project/#running-cmake-gui">https://preshing.com/20170511/how-to-build-a-cmake-based-project/#running-cmake-gui</a></li>
  <li> SDL_RWops and Related Functions : <a href="https://wiki.libsdl.org/SDL_RWops">https://wiki.libsdl.org/SDL_RWops</a></li>  
  <li> Buffers usefull stuff : <a href="https://www.quora.com/What-is-the-difference-between-declaring-a-variable-as-char-*buffer-and-char-**buffer-in-the-C-programming-language">https://www.quora.com/What-is-the-diff. . .</a></li>  
</ul>
