# Script di compilazione per programmi che usano root
# NB: nella realta' al posto di uno script si usa un Makefile

if [ $# -lt 1 ]; then
  echo "Usage: $0 files"
  echo "   es: $0 a.cxx b.cxx"
  exit
fi


LIB=`root-config --libs | sed -e 's/-lPhysics//; s/-lPostscript//; s/-lRIO//; s/-lNet//; s/-stdlib=libc++/-std=c++11y/'`
INC=`root-config --incdir`
echo g++ -I$INC $@ $LIB

g++5 -I$INC $@ $LIB
