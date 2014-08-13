
# MAKE file for TestBed.MAK     Version 2.1

# Revised:  1992-08-09

# Copyright ¸ 1987-1992  Prominare Inc.

Update: $(OBJDIR)TestBed.Obj $(OBJDIR)TestBed.Res

$(OBJDIR)TestBed.Obj: TestBed.C
 $(CC) $(C_SW)-Fo$*.Obj TestBed.C

$(OBJDIR)TestBed.Res: TestBed.Rc Default.Bmp Disabled.Bmp Down.Bmp TestBed.Ico
 $(RC) $(RC_SW) TestBed.Rc $*.Res

