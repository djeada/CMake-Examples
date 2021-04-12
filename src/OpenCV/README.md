# Open-CV

```bash
sudo apt update && sudo apt install -y cmake g++ wget unzip
wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip
unzip opencv.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/master.zip
unzip opencv_contrib.zip
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo \
      -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-master/modules \
      -DCMAKE_INSTALL_PREFIX=$HOME/local/ \
      ../opencv-master/
make -j10
make install

```
