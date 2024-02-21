# test f32

rm -r -force .xmake
rm -r -force ./build

xmake f --float_width_32=y --float_width_64=n 
xmake build
xmake run test_float
xmake run test_complex
xmake run test_fft

# test f64

rm -r -force .xmake
rm -r -force ./build

xmake build
xmake run test_float
xmake run test_complex
xmake run test_fft