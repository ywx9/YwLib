@echo off

@REM 定数
SET HERE=%~dp0
SET IFC=%HERE%ywlib.ifc
SET IXX=%HERE%ywlib.ixx
SET OBJ=%HERE%ywlib.obj

@REM パスをmsvc/batに設定
SET PATH=%HERE%msvc\bin;

@REM 引数の数が0ならBUILD_IFCへ
if "%1" == "" goto BUILD_IFC

@REM モジュールをビルドする
:BUILD_IFC
@REM 1. 既にywlib.ifcやywlib.objがあれば削除
if exist %IFC% del %IFC%
if exist %OBJ% del %OBJ%
@REM 2. ywlib.ixxを作成し、export module yw;\n#include "hack/xyz.h"\nを書き込む
echo export module yw; > %IXX%
echo #include "hack/xyz.h" >> %IXX%
@REM 3. ywlib.ixxをコンパイルし、ywlib.ifcとywlib.objを作成
cl /std:c++latest /EHsc /nologo /MT /W4 /O2 /Qpar /utf-8 ^
%IXX% /c /D__ywstd_export=export /wd5244 /ifcOutput%IFC% /Fo%OBJ% /I%HERE%hack /I%HERE%msvc\inc
@REM 4. ywlib.ixxを削除
del %IXX%
@REM 5. 終了
goto END

@REM 実行ファイルをビルドする
:BUILD_EXE
@REM 1. %1が.cppでなければ使用方法を表示して終了
if not "%1" == "*.cpp" (
  echo "Usage:"
  echo "  ./.compile -> build ywlib"
  echo "  ./.compile [cpp_file] -> build [cpp_file] by ywlib"
  goto END
)
SET CPP_FILE=%1
SET EXE_FILE=%1
SET EXE_FILE=%EXE_FILE:.cpp=.exe%
SET OBJ_FILE=%1
SET OBJ_FILE=%OBJ_FILE:.cpp=.obj%
@REM 2. ywlib.ifcとywlib.objを使ってCPP_FILEをビルド
cl /std:c++latest /EHsc /nologo /MT /W4 /O2 /Qpar /utf-8 ^
%CPP_FILE% /D__ywstd_import /Fe%EXE_FILE% /Fo%OBJ_FILE% /referenceywstd=%IFC% /I%HERE% /link %OBJ% /LIBPATH:%HERE%msvc\lib
@REM 3. OBJ_FILEを削除
del %OBJ_FILE%
@REM 4. もし%2が--runならEXE_FILEを実行
if "%2" == "--run" (
  %EXE_FILE%
)
@REM 5. 終了
goto END

:END
