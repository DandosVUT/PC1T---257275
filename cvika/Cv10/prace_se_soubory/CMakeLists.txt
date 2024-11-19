# CMakeList.txt: Projekt CMake pro prace_se_soubory, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#
cmake_minimum_required (VERSION 3.8)

# Pokud je to podporováno, povolte Opětovné načítání za provozu pro kompilátory MSVC.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("prace_se_soubory")

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (prace_se_soubory "prace_se_soubory.cpp" "prace_se_soubory.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET prace_se_soubory PROPERTY CXX_STANDARD 20)
endif()

# TODO: V případě potřeby přidejte testy a cíle instalace.
