
<a href="https://github.com/djeada/CMake/tree/main/src/ExportingAndUsingPackages/ExportingPackages">Exporting packages</a> directory contains an example of a library that can be exported as a package.

In order to do so, you need to go that directory and run the following commands:

```bash
mkdir build
cd build
cmake..
cmake --build .
sudo make install
```

Now your package has been installed and you can use it in any other project.
If you wonder how, I would recommend you to take a look at <a href="https://github.com/djeada/CMake/tree/main/src/ExportingAndUsingPackages/UsingPackages">Using Packages</a> directory.
