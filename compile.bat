@echo off

@REM 定数
SET HERE=%~dp0
SET IFC=%HERE%ywlib.ifc
SET IXX=%HERE%ywlib.ixx
SET OBJ=%HERE%ywlib.obj

@REM パスをmsvc/batに設定
SET PATH=%HERE%msvc\bin;

@REM フラグ
SET BUILD_ALL=0
SET RUN_EXE=0

@REM 引数の数が0ならBUILD_IFCへ
if "%1" == "" goto BUILD_IFC

@REM 複数ある引数のどれかに"--all"が含まれていたらBUILD_ALLを1に
for %%i in (%*) do ( if "%%i" == "--all" ( SET BUILD_ALL=1 ) )
echo "BUILD_ALL: %BUILD_ALL%"

@REM BUILD_ALLが0ならBUILD_EXEへ
if %BUILD_ALL% == 0 goto BUILD_EXE

@REM モジュールをビルドする
@REM 1. 既にywlib.ifcやywlib.objがあれば削除
@REM 2. ywlib.ixxを作成し、export module yw;\n#include "hack/xyz.h"\nを書き込む
@REM 3. ywlib.ixxをコンパイルし、ywlib.ifcとywlib.objを作成
:BUILD_IFC
if exist %IFC% del %IFC%
if exist %OBJ% del %OBJ%
echo export module yw; > %IXX%
echo #include "hack/xyz.h" >> %IXX%
cl /c %IXX% /D__ywstd_export=export /std:c++latest /EHsc /nologo /MT /W4 /wd5244 /O2 /Qpar /utf-8 /ifcOutput%IFC% /Fo%OBJ% /I%HERE%hack /I%HERE%msvc\inc

@REM BUILD_ALLでなければ終了
if %BUILD_ALL% == 0 goto END

:BUILD_EXE
@REM %1が.cppでなければ使用方法を表示して終了
if not "%1" == "*.cpp" (
  echo "Usage:"
  echo "  ./compile -> build ywlib"
  echo "  ./compile [cpp_file] -> build [cpp_file] by ywlib"
  echo "  ./compile [cpp_file] --all -> build ywlib and [cpp_file]"
  goto END
)

SET CPP_FILE=%1
SET EXE_FILE=%1
SET EXE_FILE=%EXE_FILE:.cpp=.exe%
SET OBJ_FILE=%1
SET OBJ_FILE=%OBJ_FILE:.cpp=.obj%
@REM 実行ファイルをビルドする
@REM 1. ywlib.ifcとywlib.objを使って%1をビルド
@REM 2.

:END
