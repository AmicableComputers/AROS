/****************************************************************
   This file was created automatically by `FlexCat 2.19'
   from "/root/aros-vamp/workbench/tools/WiMP/catalogs/WiMP.cd".

   Do NOT edit by hand!
****************************************************************/

#ifndef WIMP_STRINGS_H
#define WIMP_STRINGS_H


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif


#ifdef CATCOMP_ARRAY
#ifndef CATCOMPARRAY
#define CATCOMPARRAY CatCompArray
#endif
#undef CATCOMP_NUMBERS
#undef CATCOMP_STRINGS
#define CATCOMP_NUMBERS
#define CATCOMP_STRINGS
#endif

#ifdef CATCOMP_BLOCK
#undef CATCOMP_STRINGS
#define CATCOMP_STRINGS
#endif

/***************************************************************/

#ifdef CATCOMP_NUMBERS

#define MSG_APP_NAME 0
#define MSG_APP_TITLE 1
#define MSG_APP_ABOUT 2
#define MSG_APP_COPYRIGHT 3
#define MSG_APP_AUTOR 4
#define MSG_APP_BASE 5
#define MSG_WINDOW_TITLE 6
#define MSG_INFO_TITLE 7
#define MSG_CLOSE_SCREEN 8
#define MSG_CLOSE_WINDOW 9
#define MSG_YES_NO 10
#define MSG_CONTINUE 11
#define MSG_BTN_KILL 12
#define MSG_BTN_FRONT 13
#define MSG_BTN_BACK 14
#define MSG_BTN_MOVE 15
#define MSG_BTN_ACTIVATE 16
#define MSG_BTN_ZIP 17
#define MSG_BTN_HIDE 18
#define MSG_BTN_SHOW 19
#define MSG_BTN_UPDATE_LIST 20
#define MSG_BTN_RESCUE_ALL 21
#define MSG_BTN_SHOW_ALL 22
#define MSG_BTN_RETHING 23
#define MSG_BTN_ABOUT 24
#define MSG_SCREEN_WINDOW_LIST 25
#define MSG_MENU_PROJECT 26
#define MSG_MENU_ABOUT 27
#define MSG_MENU_QUIT 28
#define MSG_MENU_WIN_LIST 29
#define MSG_MENU_UPDATE_LIST 30
#define MSG_MENU_KILL 31
#define MSG_MENU_TO_FRONT 32
#define MSG_MENU_TO_BACK 33
#define MSG_MENU_TO_ORIGIN 34
#define MSG_MENU_ACTIVATE 35
#define MSG_MENU_ZIP 36
#define MSG_MENU_HIDE 37
#define MSG_MENU_SHOW 38
#define MSG_MENU_INFO 39
#define MSG_MENU_GENERIC 40
#define MSG_MENU_RESCUE_ALL 41
#define MSG_MENU_SHOW_ALL 42
#define MSG_MENU_RETHINGDISPLAY 43
#define MSG_ARRAY_WINDOW 44
#define MSG_ARRAY_SCREEN 45
#define MSG_ARRAY_0_TYPE 46
#define MSG_ARRAY_1_ADDRESS 47
#define MSG_ARRAY_2_SIZE 48
#define MSG_ARRAY_3_POSITION 49
#define MSG_ARRAY_4_STATUS 50
#define MSG_ARRAY_5_TITLE 51
#define MSG_COL_SCREEN 52
#define MSG_COL_SCR_ADDRESS 53
#define MSG_COL_SCR_LEFTEDGE 54
#define MSG_COL_SCR_TOPEDGE 55
#define MSG_COL_SCR_WIDTH 56
#define MSG_COL_SCR_HEIGHT 57
#define MSG_COL_SCR_FLAGS 58
#define MSG_COL_SCR_TITLE 59
#define MSG_COL_SCR_DEFAULTIT 60
#define MSG_COL_SCR_FRSTWIN 61
#define MSG_COL_WIDOW 62
#define MSG_COL_WIN_ADDRESS 63
#define MSG_COL_WIN_NEXTWIN 64
#define MSG_COL_WIN_LEFTEDGE 65
#define MSG_COL_WIN_TOPEDGE 66
#define MSG_COL_WIN_WIDTH 67
#define MSG_COL_WIN_HEIGHT 68
#define MSG_COL_WIN_MINWIDTH 69
#define MSG_COL_WIN_MINHEIGHT 70
#define MSG_COL_WIN_MAXWIDTH 71
#define MSG_COL_WIN_MAXHEIGHT 72
#define MSG_COL_WIN_FLAGS 73
#define MSG_COL_WIN_IDCMPFLAGS 74
#define MSG_COL_WIN_TITLE 75
#define MSG_COL_WIN_REQCOUNT 76
#define MSG_COL_WIN_WSCREEN 77
#define MSG_COL_WIN_BORDERLEFT 78
#define MSG_COL_WIN_BORDERTOP 79
#define MSG_COL_WIN_BORDERRIGHT 80
#define MSG_COL_WIN_BORDERBOTTOM 81
#define MSG_COL_WIN_PARENTWIN 82
#define MSG_COL_WIN_FIRSTCHILD 83
#define MSG_COL_WIN_PARENT 84
#define MSG_COL_WIN_DESCENDANT 85

#endif /* CATCOMP_NUMBERS */

/***************************************************************/

#ifdef CATCOMP_STRINGS

#define MSG_APP_NAME_STR "WiMP"
#define MSG_APP_TITLE_STR "Window Manipulator"
#define MSG_APP_ABOUT_STR "WiMP - The Window Manipulation Program\n\nCopyright � 2000-2019 by The AROS Development Team"
#define MSG_APP_COPYRIGHT_STR "Copyright � 1995-2019, The AROS Development Team"
#define MSG_APP_AUTOR_STR "The AROS Development Team"
#define MSG_APP_BASE_STR "WIMP"
#define MSG_WINDOW_TITLE_STR "WiMP - The Window Manipulation Program"
#define MSG_INFO_TITLE_STR "WiMP - InfoWindow"
#define MSG_CLOSE_SCREEN_STR "Do you really want to Close the selected Screen?"
#define MSG_CLOSE_WINDOW_STR "Do you really want to Close the selected Window?"
#define MSG_YES_NO_STR "Yes.|No!"
#define MSG_CONTINUE_STR "Continue"
#define MSG_BTN_KILL_STR "\033iKill"
#define MSG_BTN_FRONT_STR "To _Front"
#define MSG_BTN_BACK_STR "To _Back"
#define MSG_BTN_MOVE_STR "Move to _Origin"
#define MSG_BTN_ACTIVATE_STR "_Activate"
#define MSG_BTN_ZIP_STR "_Zip"
#define MSG_BTN_HIDE_STR "_Hide"
#define MSG_BTN_SHOW_STR "_Show"
#define MSG_BTN_UPDATE_LIST_STR "_Update List"
#define MSG_BTN_RESCUE_ALL_STR "_Rescue all Windows"
#define MSG_BTN_SHOW_ALL_STR "Show all Windows"
#define MSG_BTN_RETHING_STR "Rethink Display"
#define MSG_BTN_ABOUT_STR "About"
#define MSG_SCREEN_WINDOW_LIST_STR "Screen/Window List"
#define MSG_MENU_PROJECT_STR "Project"
#define MSG_MENU_ABOUT_STR "About..."
#define MSG_MENU_QUIT_STR "Quit"
#define MSG_MENU_WIN_LIST_STR "Window List"
#define MSG_MENU_UPDATE_LIST_STR "Update List"
#define MSG_MENU_KILL_STR "Kill"
#define MSG_MENU_TO_FRONT_STR "To Front"
#define MSG_MENU_TO_BACK_STR "To Back"
#define MSG_MENU_TO_ORIGIN_STR "To Origin"
#define MSG_MENU_ACTIVATE_STR "Activate"
#define MSG_MENU_ZIP_STR "Zip"
#define MSG_MENU_HIDE_STR "Hide"
#define MSG_MENU_SHOW_STR "Show"
#define MSG_MENU_INFO_STR "Info"
#define MSG_MENU_GENERIC_STR "Generic"
#define MSG_MENU_RESCUE_ALL_STR "Rescue All"
#define MSG_MENU_SHOW_ALL_STR "Show All"
#define MSG_MENU_RETHINGDISPLAY_STR "RethinkDisplay"
#define MSG_ARRAY_WINDOW_STR "  \033bWindow"
#define MSG_ARRAY_SCREEN_STR "\033b\033uScreen"
#define MSG_ARRAY_0_TYPE_STR "Type"
#define MSG_ARRAY_1_ADDRESS_STR "Address"
#define MSG_ARRAY_2_SIZE_STR "Size"
#define MSG_ARRAY_3_POSITION_STR "Position"
#define MSG_ARRAY_4_STATUS_STR "Status"
#define MSG_ARRAY_5_TITLE_STR "Title"
#define MSG_COL_SCREEN_STR "Screen"
#define MSG_COL_SCR_ADDRESS_STR "Address"
#define MSG_COL_SCR_LEFTEDGE_STR "LeftEdge"
#define MSG_COL_SCR_TOPEDGE_STR "TopEdge"
#define MSG_COL_SCR_WIDTH_STR "Width"
#define MSG_COL_SCR_HEIGHT_STR "Height"
#define MSG_COL_SCR_FLAGS_STR "Flags"
#define MSG_COL_SCR_TITLE_STR "Title"
#define MSG_COL_SCR_DEFAULTIT_STR "DefaultTitle"
#define MSG_COL_SCR_FRSTWIN_STR "FirstWindow"
#define MSG_COL_WIDOW_STR "Window"
#define MSG_COL_WIN_ADDRESS_STR "Address"
#define MSG_COL_WIN_NEXTWIN_STR "NextWindow"
#define MSG_COL_WIN_LEFTEDGE_STR "LeftEdge"
#define MSG_COL_WIN_TOPEDGE_STR "TopEdge"
#define MSG_COL_WIN_WIDTH_STR "Width"
#define MSG_COL_WIN_HEIGHT_STR "Height"
#define MSG_COL_WIN_MINWIDTH_STR "MinWidth"
#define MSG_COL_WIN_MINHEIGHT_STR "MinHeight"
#define MSG_COL_WIN_MAXWIDTH_STR "MaxWidth"
#define MSG_COL_WIN_MAXHEIGHT_STR "MaxHeight"
#define MSG_COL_WIN_FLAGS_STR "Flags"
#define MSG_COL_WIN_IDCMPFLAGS_STR "IDCMPFlags"
#define MSG_COL_WIN_TITLE_STR "Title"
#define MSG_COL_WIN_REQCOUNT_STR "ReqCount"
#define MSG_COL_WIN_WSCREEN_STR "WScreen"
#define MSG_COL_WIN_BORDERLEFT_STR "BorderLeft"
#define MSG_COL_WIN_BORDERTOP_STR "BorderTop"
#define MSG_COL_WIN_BORDERRIGHT_STR "BorderRight"
#define MSG_COL_WIN_BORDERBOTTOM_STR "BoderBottom"
#define MSG_COL_WIN_PARENTWIN_STR "Parent Window"
#define MSG_COL_WIN_FIRSTCHILD_STR "First Child"
#define MSG_COL_WIN_PARENT_STR "Parent"
#define MSG_COL_WIN_DESCENDANT_STR "Descendant"

#endif /* CATCOMP_STRINGS */

/***************************************************************/

#ifdef CATCOMP_ARRAY

#ifndef HAVE_CATCOMP_ARRAYTYPE
#define HAVE_CATCOMP_ARRAYTYPE
struct CatCompArrayType
{
  IPTR   cca_ID;
  STRPTR cca_Str;
};
#endif

static const struct CatCompArrayType CATCOMPARRAY[] =
{
  {MSG_APP_NAME,(STRPTR)MSG_APP_NAME_STR},
  {MSG_APP_TITLE,(STRPTR)MSG_APP_TITLE_STR},
  {MSG_APP_ABOUT,(STRPTR)MSG_APP_ABOUT_STR},
  {MSG_APP_COPYRIGHT,(STRPTR)MSG_APP_COPYRIGHT_STR},
  {MSG_APP_AUTOR,(STRPTR)MSG_APP_AUTOR_STR},
  {MSG_APP_BASE,(STRPTR)MSG_APP_BASE_STR},
  {MSG_WINDOW_TITLE,(STRPTR)MSG_WINDOW_TITLE_STR},
  {MSG_INFO_TITLE,(STRPTR)MSG_INFO_TITLE_STR},
  {MSG_CLOSE_SCREEN,(STRPTR)MSG_CLOSE_SCREEN_STR},
  {MSG_CLOSE_WINDOW,(STRPTR)MSG_CLOSE_WINDOW_STR},
  {MSG_YES_NO,(STRPTR)MSG_YES_NO_STR},
  {MSG_CONTINUE,(STRPTR)MSG_CONTINUE_STR},
  {MSG_BTN_KILL,(STRPTR)MSG_BTN_KILL_STR},
  {MSG_BTN_FRONT,(STRPTR)MSG_BTN_FRONT_STR},
  {MSG_BTN_BACK,(STRPTR)MSG_BTN_BACK_STR},
  {MSG_BTN_MOVE,(STRPTR)MSG_BTN_MOVE_STR},
  {MSG_BTN_ACTIVATE,(STRPTR)MSG_BTN_ACTIVATE_STR},
  {MSG_BTN_ZIP,(STRPTR)MSG_BTN_ZIP_STR},
  {MSG_BTN_HIDE,(STRPTR)MSG_BTN_HIDE_STR},
  {MSG_BTN_SHOW,(STRPTR)MSG_BTN_SHOW_STR},
  {MSG_BTN_UPDATE_LIST,(STRPTR)MSG_BTN_UPDATE_LIST_STR},
  {MSG_BTN_RESCUE_ALL,(STRPTR)MSG_BTN_RESCUE_ALL_STR},
  {MSG_BTN_SHOW_ALL,(STRPTR)MSG_BTN_SHOW_ALL_STR},
  {MSG_BTN_RETHING,(STRPTR)MSG_BTN_RETHING_STR},
  {MSG_BTN_ABOUT,(STRPTR)MSG_BTN_ABOUT_STR},
  {MSG_SCREEN_WINDOW_LIST,(STRPTR)MSG_SCREEN_WINDOW_LIST_STR},
  {MSG_MENU_PROJECT,(STRPTR)MSG_MENU_PROJECT_STR},
  {MSG_MENU_ABOUT,(STRPTR)MSG_MENU_ABOUT_STR},
  {MSG_MENU_QUIT,(STRPTR)MSG_MENU_QUIT_STR},
  {MSG_MENU_WIN_LIST,(STRPTR)MSG_MENU_WIN_LIST_STR},
  {MSG_MENU_UPDATE_LIST,(STRPTR)MSG_MENU_UPDATE_LIST_STR},
  {MSG_MENU_KILL,(STRPTR)MSG_MENU_KILL_STR},
  {MSG_MENU_TO_FRONT,(STRPTR)MSG_MENU_TO_FRONT_STR},
  {MSG_MENU_TO_BACK,(STRPTR)MSG_MENU_TO_BACK_STR},
  {MSG_MENU_TO_ORIGIN,(STRPTR)MSG_MENU_TO_ORIGIN_STR},
  {MSG_MENU_ACTIVATE,(STRPTR)MSG_MENU_ACTIVATE_STR},
  {MSG_MENU_ZIP,(STRPTR)MSG_MENU_ZIP_STR},
  {MSG_MENU_HIDE,(STRPTR)MSG_MENU_HIDE_STR},
  {MSG_MENU_SHOW,(STRPTR)MSG_MENU_SHOW_STR},
  {MSG_MENU_INFO,(STRPTR)MSG_MENU_INFO_STR},
  {MSG_MENU_GENERIC,(STRPTR)MSG_MENU_GENERIC_STR},
  {MSG_MENU_RESCUE_ALL,(STRPTR)MSG_MENU_RESCUE_ALL_STR},
  {MSG_MENU_SHOW_ALL,(STRPTR)MSG_MENU_SHOW_ALL_STR},
  {MSG_MENU_RETHINGDISPLAY,(STRPTR)MSG_MENU_RETHINGDISPLAY_STR},
  {MSG_ARRAY_WINDOW,(STRPTR)MSG_ARRAY_WINDOW_STR},
  {MSG_ARRAY_SCREEN,(STRPTR)MSG_ARRAY_SCREEN_STR},
  {MSG_ARRAY_0_TYPE,(STRPTR)MSG_ARRAY_0_TYPE_STR},
  {MSG_ARRAY_1_ADDRESS,(STRPTR)MSG_ARRAY_1_ADDRESS_STR},
  {MSG_ARRAY_2_SIZE,(STRPTR)MSG_ARRAY_2_SIZE_STR},
  {MSG_ARRAY_3_POSITION,(STRPTR)MSG_ARRAY_3_POSITION_STR},
  {MSG_ARRAY_4_STATUS,(STRPTR)MSG_ARRAY_4_STATUS_STR},
  {MSG_ARRAY_5_TITLE,(STRPTR)MSG_ARRAY_5_TITLE_STR},
  {MSG_COL_SCREEN,(STRPTR)MSG_COL_SCREEN_STR},
  {MSG_COL_SCR_ADDRESS,(STRPTR)MSG_COL_SCR_ADDRESS_STR},
  {MSG_COL_SCR_LEFTEDGE,(STRPTR)MSG_COL_SCR_LEFTEDGE_STR},
  {MSG_COL_SCR_TOPEDGE,(STRPTR)MSG_COL_SCR_TOPEDGE_STR},
  {MSG_COL_SCR_WIDTH,(STRPTR)MSG_COL_SCR_WIDTH_STR},
  {MSG_COL_SCR_HEIGHT,(STRPTR)MSG_COL_SCR_HEIGHT_STR},
  {MSG_COL_SCR_FLAGS,(STRPTR)MSG_COL_SCR_FLAGS_STR},
  {MSG_COL_SCR_TITLE,(STRPTR)MSG_COL_SCR_TITLE_STR},
  {MSG_COL_SCR_DEFAULTIT,(STRPTR)MSG_COL_SCR_DEFAULTIT_STR},
  {MSG_COL_SCR_FRSTWIN,(STRPTR)MSG_COL_SCR_FRSTWIN_STR},
  {MSG_COL_WIDOW,(STRPTR)MSG_COL_WIDOW_STR},
  {MSG_COL_WIN_ADDRESS,(STRPTR)MSG_COL_WIN_ADDRESS_STR},
  {MSG_COL_WIN_NEXTWIN,(STRPTR)MSG_COL_WIN_NEXTWIN_STR},
  {MSG_COL_WIN_LEFTEDGE,(STRPTR)MSG_COL_WIN_LEFTEDGE_STR},
  {MSG_COL_WIN_TOPEDGE,(STRPTR)MSG_COL_WIN_TOPEDGE_STR},
  {MSG_COL_WIN_WIDTH,(STRPTR)MSG_COL_WIN_WIDTH_STR},
  {MSG_COL_WIN_HEIGHT,(STRPTR)MSG_COL_WIN_HEIGHT_STR},
  {MSG_COL_WIN_MINWIDTH,(STRPTR)MSG_COL_WIN_MINWIDTH_STR},
  {MSG_COL_WIN_MINHEIGHT,(STRPTR)MSG_COL_WIN_MINHEIGHT_STR},
  {MSG_COL_WIN_MAXWIDTH,(STRPTR)MSG_COL_WIN_MAXWIDTH_STR},
  {MSG_COL_WIN_MAXHEIGHT,(STRPTR)MSG_COL_WIN_MAXHEIGHT_STR},
  {MSG_COL_WIN_FLAGS,(STRPTR)MSG_COL_WIN_FLAGS_STR},
  {MSG_COL_WIN_IDCMPFLAGS,(STRPTR)MSG_COL_WIN_IDCMPFLAGS_STR},
  {MSG_COL_WIN_TITLE,(STRPTR)MSG_COL_WIN_TITLE_STR},
  {MSG_COL_WIN_REQCOUNT,(STRPTR)MSG_COL_WIN_REQCOUNT_STR},
  {MSG_COL_WIN_WSCREEN,(STRPTR)MSG_COL_WIN_WSCREEN_STR},
  {MSG_COL_WIN_BORDERLEFT,(STRPTR)MSG_COL_WIN_BORDERLEFT_STR},
  {MSG_COL_WIN_BORDERTOP,(STRPTR)MSG_COL_WIN_BORDERTOP_STR},
  {MSG_COL_WIN_BORDERRIGHT,(STRPTR)MSG_COL_WIN_BORDERRIGHT_STR},
  {MSG_COL_WIN_BORDERBOTTOM,(STRPTR)MSG_COL_WIN_BORDERBOTTOM_STR},
  {MSG_COL_WIN_PARENTWIN,(STRPTR)MSG_COL_WIN_PARENTWIN_STR},
  {MSG_COL_WIN_FIRSTCHILD,(STRPTR)MSG_COL_WIN_FIRSTCHILD_STR},
  {MSG_COL_WIN_PARENT,(STRPTR)MSG_COL_WIN_PARENT_STR},
  {MSG_COL_WIN_DESCENDANT,(STRPTR)MSG_COL_WIN_DESCENDANT_STR},
  {0,NULL}
};

#endif /* CATCOMP_ARRAY */

/***************************************************************/

#ifdef CATCOMP_BLOCK

#error CATCOMP_BLOCK not supported by this SD

#endif /* CATCOMP_BLOCK */

/***************************************************************/

#ifdef CATCOMP_CODE

#error CATCOMP_CODE not supported by this SD

#endif /* CATCOMP_CODE */

/***************************************************************/


#endif /* WIMP_STRINGS_H */
