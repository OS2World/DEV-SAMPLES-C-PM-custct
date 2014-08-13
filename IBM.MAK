
# MAKE file for ImageBtn.Mak     Version  1.0

# Revised:  1993-01-27

ImageBtn.Dll: ImageBtn.Obj ImageBtn.Res
 link386 /EXEPACK @IBM.lnk;
 rc ImageBtn.Res ImageBtn.Dll

ImageBtn.Obj: ImageBtn.C
 icc -G3e- -O+ -Rn -W3 -C -Fo$*.Obj ImageBtn.C

ImageBtn.Res: ImageBtn.Rc Default.Bmp Disabled.Bmp Down.Bmp
 rc -r ImageBtn.Rc $*.Res
