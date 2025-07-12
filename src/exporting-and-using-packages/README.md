
 Export the library as a package and include it in an entirely unrelated project.

In order to do so, you need to go that directory and run the following commands:

```bash
mkdir build
cd build
cmake..
cmake --build .
sudo make install
```

Your package is now installed and ready to use on some other project.
If you're wondering how, I suggest you look at the <a href="https://github.com/djeada/CMake/tree/main/src/ExportingAndUsingPackages/UsingPackages">Using Packages</a> directory.
