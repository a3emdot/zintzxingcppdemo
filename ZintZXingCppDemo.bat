echo on

call %cd%\windowsenv.bat

if NOT DEFINED WORKSPACE (
  set WORKSPACE=%cd%
)

if NOT DEFINED CI_JOB_NAME (
    set CI_JOB_NAME=local
)

if NOT DEFINED CMAKE_BUILD_TYPE (
  set CMAKE_BUILD_TYPE=Release
)

set SOURCE_DIR=%WORKSPACE%
set BINARY_DIR=%WORKSPACE%\build\%CI_JOB_NAME%

set PATH=%BINARY_DIR%\deps\instal\bin;%PATH%

cmake -E rm -rf %BINARY_DIR%

cmake -S %SOURCE_DIR%\deps -B %BINARY_DIR%\deps -DCMAKE_BUILD_TYPE=%CMAKE_BUILD_TYPE%
cmake --build %BINARY_DIR%\deps --config %CMAKE_BUILD_TYPE%

cmake -S %SOURCE_DIR% -B %BINARY_DIR% -DCMAKE_BUILD_TYPE=%CMAKE_BUILD_TYPE%
cmake --build %BINARY_DIR% --config %CMAKE_BUILD_TYPE%

cmake -E chdir %BINARY_DIR% ctest -C %CMAKE_BUILD_TYPE%

