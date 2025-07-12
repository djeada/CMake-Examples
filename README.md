

# 🚀 CMake Examples

**A curated collection of modern C++ project templates and best practices using CMake.**

---

## ✨ What is this?

This repository is your go-to resource for learning, prototyping, and kickstarting C++ projects with CMake.  
It demonstrates real-world setups for:

- Executables and libraries
- Modular subdirectory organization
- Exporting and consuming CMake packages
- Integrating OpenCV, MPI, Clang-Tidy, and GoogleTest
- Automated code formatting and build checks

---

## 💡 Why CMake?

CMake is the industry standard for cross-platform C++ builds.  
It empowers you to:

- Build on Linux, macOS, and Windows with a single config
- Integrate seamlessly with IDEs and CI/CD
- Use modern C++ workflows and toolchains

---

## 🏁 Getting Started

1. **Clone the repo**
   ```bash
   git clone https://github.com/djeada/CMake-Examples.git
   cd CMake-Examples
   ```
2. **Build an example**
   ```bash
   cd src/<example-dir>
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```
3. **Check formatting and compilation**
   ```bash
   bash tests/check_format.sh
   bash tests/test_compile.sh
   ```

---

## 🗂️ Project Structure

```
src/
  clang-tidy/                  # Clang-Tidy integration
  executables-and-libraries/   # Executable & library example
  exporting-and-using-packages/
    exporting-packages/
    using-packages/
  gtest/                       # GoogleTest integration
  mpi/                         # MPI example
  opencv/                      # OpenCV example
  subdirectories/              # Modular subdirectory example
tests/                         # Formatting & build scripts
.github/workflows/ci.yml       # Automated CI workflow
```

---

## 📚 Example Index

- [Executables & Libraries](src/executables-and-libraries)
- [Subdirectories](src/subdirectories)
- [Exporting & Using Packages](src/exporting-and-using-packages)
- [OpenCV Integration](src/opencv)
- [MPI Example](src/mpi)
- [Clang-Tidy Integration](src/clang-tidy)
- [GoogleTest Integration](src/gtest)

---

## 🛡️ Automated Quality

- `tests/check_format.sh`: Enforces modern C++ style (clang-format)
- `tests/test_compile.sh`: Verifies all examples build
- **GitHub Actions CI**: Runs checks on every push & PR

---

## ⚙️ Requirements

- CMake v3.15+
- GCC or Clang
- Make

---

## 🤝 Contributing

Pull requests and issues are welcome!  
Please follow formatting standards and include relevant tests.

---

## 📄 License

MIT License. See [LICENSE](https://choosealicense.com/licenses/mit/).

---

Ready to build something great?  
**Explore, learn, and ship modern C++ with CMake!**
