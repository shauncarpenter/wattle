solution "wattle"
  configurations "Debug"
  flags {"Symbols"}
  buildoptions {"-g", "-std=c99"}

  project "table_test"
    kind "ConsoleApp"
    language "C"
    files {"./*.c", "./*.c"}
    excludes {"wat*"}
    
