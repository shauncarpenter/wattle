Solution "Sol"
  configurations "Debug"
  flags {"Symbol"}
  buildoptions {"-g"}

  --solc is the compiler which converts sol code into c code
  project "solc"
    kind "ConsoleApp"
    language "C" --FUCK C++
    files {"./src/*.h", "./src/*.cpp"}
    links {"tcc"}
