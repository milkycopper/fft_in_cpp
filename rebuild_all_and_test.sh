xmake f --toolchain=clang -c

# test f32

rm -rf .xmake
rm -rf ./build

xmake f --float_width_32=y --float_width_64=n 
xmake build
xmake run test_float
xmake run test_complex
xmake run test_fft

# test f64

rm -rf .xmake
rm -rf ./build

xmake build
xmake run test_float
xmake run test_complex
xmake run test_fft