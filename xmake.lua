add_rules("mode.debug")
add_requires("gtest")

set_languages("c++17")

option("float_width_32")
    set_default(false)
    set_showmenu(true)
    add_defines("FLOAT_32")

option("float_width_64")
    set_default(true)
    set_showmenu(true)
    add_defines("FLOAT_64")

if has_config("float_width_32") then
    print("FLOAT WIDTH = 32")
end

if has_config("float_width_64") then
    print("FLOAT WIDTH = 64")
end

target("float")
    set_kind("static")
    add_includedirs("include/float", {public = true})
    add_options("float_width_32")
    add_options("float_width_64")
    add_files("src/float/*.cpp")

target("test_float")
    set_kind("binary")
    set_group("tests")
    add_files("test/test_float.cpp")
    add_deps("float")
    add_options("float_width_32")
    add_options("float_width_64")
    add_packages("gtest")

target("complex")
    set_kind("static")
    add_includedirs("include/complex", {public = true})
    add_deps("float")
    add_options("float_width_32")
    add_options("float_width_64")
    add_files("src/complex/*.cpp")

target("test_complex")
    set_kind("binary")
    set_group("tests")
    add_files("test/test_complex.cpp")
    add_deps("complex")
    add_options("float_width_32")
    add_options("float_width_64")
    add_packages("gtest")

target("fft")
    set_kind("static")
    add_includedirs("include/fft", {public = true})
    add_deps("float")
    add_options("float_width_32")
    add_options("float_width_64")
    add_deps("complex")
    add_files("src/fft/*.cpp")

target("test_fft")
    set_kind("binary")
    set_group("tests")
    add_files("test/fft/*.cpp")
    add_includedirs("test/fft")
    add_deps("complex")
    add_deps("fft")
    add_options("float_width_32")
    add_options("float_width_64")
    add_packages("gtest")

    