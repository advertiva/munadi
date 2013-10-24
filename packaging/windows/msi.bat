@ echo off

rem Stick everything needed to run Munadi in Munadi folder then continue with this script...

set /p version=Type version (e.g. 1.2.0.0):

PATH = %PATH%;D:\wix36

candle -ext WixUtilExtension.dll munadi.wxs
light -ext WixUtilExtension.dll -ext WixUIExtension.dll munadi.wixobj -out munadi-%version%.msi

del /f .\*.wixobj
del /f .\*.wixpdb

pause

@ echo on