
ppd08office03ps.dll: dlldata.obj ppd08office03_p.obj ppd08office03_i.obj
	link /dll /out:ppd08office03ps.dll /def:ppd08office03ps.def /entry:DllMain dlldata.obj ppd08office03_p.obj ppd08office03_i.obj \
		kernel32.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ppd08office03ps.dll
	@del ppd08office03ps.lib
	@del ppd08office03ps.exp
	@del dlldata.obj
	@del ppd08office03_p.obj
	@del ppd08office03_i.obj
