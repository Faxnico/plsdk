# Top level Application.mk to force dependencies to build
PLASTICLOGIC_NDK_BUILD := 1
APP_PLATFORM := android-8
APP_MODULES := \
	epview eptest plinput plottest \
	mod_plepaper_imx mod_plepaper_plepdc mod_plepaper_epson \
	_plsdk _imaging
