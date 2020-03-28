<h1  align="center" id="ZIPManagement_PhysFS">Assets ZIP management with PhysFS</h1>

<p>Welcome to the webpage of how to implement <a href="https://github.com/AaronGCProg/ZIPManagement_PhysFS">Assets ZIP management with PhysicsFS</a></p>

<h2  align="center" id="ZIPManagement_PhysFS">What is PhysicsFS?</h2>

<p align="justify"><b>Explanation from <a href="https://icculus.org/physfs/">icculus.org</a></b>: PhysicsFS is a library to provide abstract access to various archives. It is intended for use in video games, and the design was somewhat inspired by Quake 3's file subsystem. The programmer defines a "write directory" on the physical filesystem. No file writing done through the PhysicsFS API can leave that write directory, for security. For example, an embedded scripting language cannot write outside of this path if it uses PhysFS for all of its I/O, which means that untrusted scripts can run more safely. Symbolic links can be disabled as well, for added safety. For file reading, the programmer lists directories and archives that form a "search path". Once the search path is defined, it becomes a single, transparent hierarchical filesystem. This makes for easy access to ZIP files in the same way as you access a file directly on the disk, and it makes it easy to ship a new archive that will override a previous archive on a per-file basis. Finally, PhysicsFS gives you platform-abstracted means to determine if CD-ROMs are available, the user's home directory, where in the real filesystem your program is running, etc.</p> </br>

<p align="justify">In summary, PhysicsFS it's a portable, flexible file i/o abstraction. This API gives you access to a system file system in ways superior to the stdio or system i/o calls. The main benefits highlighted by the API developers are that it is portable, more secure because no file acces is permitted outside the specified dirs, and flexible because archives can be used transparently as directory structures.</p>




<p align="justify">Test </p>

<br>

