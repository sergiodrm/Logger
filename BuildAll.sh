echo =============================
echo === Build Config: Release ===
echo =============================
cd Release
cmake -DCMAKE_BUILD_TYPE=Release -D_COMPILE_EXE=ON ../
cmake --build .

echo === Build release config complete. ===


echo
echo
echo ===========================
echo === Build Config: Debug ===
echo ===========================
cd ../Debug
cmake -DCMAKE_BUILD_TYPE=Debug -D_COMPILE_EXE=ON ../
cmake --build .
echo === Build debug config complete. ===
