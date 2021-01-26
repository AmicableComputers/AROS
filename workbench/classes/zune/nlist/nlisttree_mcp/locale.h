/***************************************************************************

 NListtree.mcc - New Listtree MUI Custom Class
 Copyright (C) 1999-2001 by Carsten Scholling
 Copyright (C) 2001-2014 NList Open Source Team

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 NList classes Support Site:  http://www.sf.net/projects/nlist-classes

 $Id: C_h.sd 716 2014-01-26 09:32:35Z damato $

***************************************************************************/

 /*
  * If this file is named 'locale.h' it is automatically
  * generated by 'FlexCat' from C_h.sd. PLEASE DO NOT EDIT!!!
  */

#ifndef NListtree_mcp_LOCALE_H
#define NListtree_mcp_LOCALE_H

// catalog translation functions
extern const char *tr(const void *);
extern BOOL OpenCat(void);
extern void CloseCat(void);

// const pointers to internal strings
extern const void* const _MSG_TAB_LAYOUT;
extern const void* const _MSG_GROUP_IMAGES_COLORS;
extern const void* const _MSG_BUTTON_LABEL_CLOSED;
extern const void* const _MSG_BUTTON_SHORTCUT_CLOSED;
extern const void* const _MSG_HELP_CLOSED_IMAGE;
extern const void* const _MSG_WIN_TITLE_CLOSED_IMAGE;
extern const void* const _MSG_BUTTON_LABEL_LINES;
extern const void* const _MSG_BUTTON_SHORTCUT_LINES;
extern const void* const _MSG_HELP_LINES_COLOR;
extern const void* const _MSG_WIN_TITLE_LINES_COLOR;
extern const void* const _MSG_BUTTON_LABEL_OPEN;
extern const void* const _MSG_BUTTON_SHORTCUT_OPEN;
extern const void* const _MSG_HELP_OPEN_IMAGE;
extern const void* const _MSG_WIN_TITLE_OPEN_IMAGE;
extern const void* const _MSG_BUTTON_LABEL_SHADOW;
extern const void* const _MSG_BUTTON_SHORTCUT_SHADOW;
extern const void* const _MSG_HELP_SHADOW_COLOR;
extern const void* const _MSG_WIN_TITLE_SHADOW_COLOR;
extern const void* const _MSG_BUTTON_LABEL_SPECIAL;
extern const void* const _MSG_BUTTON_SHORTCUT_SPECIAL;
extern const void* const _MSG_HELP_SPECIAL_IMAGE;
extern const void* const _MSG_WIN_TITLE_SPECIAL_IMAGE;
extern const void* const _MSG_BUTTON_LABEL_DRAW;
extern const void* const _MSG_BUTTON_SHORTCUT_DRAW;
extern const void* const _MSG_HELP_DRAW_COLOR;
extern const void* const _MSG_WIN_TITLE_DRAW_COLOR;
extern const void* const _MSG_GROUP_STYLE;
extern const void* const _MSG_CYCLE_LABEL_STYLE;
extern const void* const _MSG_CYCLE_SHORTCUT_STYLE;
extern const void* const _MSG_HELP_STYLE;
extern const void* const _MSG_CYCLE_ITEM_STYLE_NORMAL;
extern const void* const _MSG_CYCLE_ITEM_STYLE_INSERTED;
extern const void* const _MSG_CYCLE_ITEM_STYLE_LINES;
extern const void* const _MSG_CYCLE_ITEM_STYLE_WIN98;
extern const void* const _MSG_CYCLE_ITEM_STYLE_MAC;
extern const void* const _MSG_CYCLE_ITEM_STYLE_LINES3D;
extern const void* const _MSG_CYCLE_ITEM_STYLE_WIN98PLUS;
extern const void* const _MSG_CYCLE_ITEM_STYLE_GLOW;
extern const void* const _MSG_BUTTON_LABEL_SPACE;
extern const void* const _MSG_BUTTON_SHORTCUT_SPACE;
extern const void* const _MSG_HELP_SPACE;
extern const void* const _MSG_BUTTON_LABEL_REMEMBER;
extern const void* const _MSG_BUTTON_SHORTCUT_REMEMBER;
extern const void* const _MSG_HELP_REMEMBER;
extern const void* const _MSG_BUTTON_LABEL_AUTOSCROLL;
extern const void* const _MSG_BUTTON_SHORTCUT_AUTOSCROLL;
extern const void* const _MSG_HELP_AUTOSCROLL;
extern const void* const _MSG_TAB_EXAMPLE;
extern const void* const _MSG_HELP_LISTVIEW_EXAMPLE;
extern const void* const _MSG_BUTTON_LABEL_EXPAND;
extern const void* const _MSG_BUTTON_SHORTCUT_EXPAND;
extern const void* const _MSG_BUTTON_LABEL_COLLAPSE;
extern const void* const _MSG_BUTTON_SHORTCUT_COLLAPSE;
extern const void* const _MSG_BUTTON_LABEL_LINETYPES;
extern const void* const _MSG_BUTTON_SHORTCUT_LINETYPES;
extern const void* const _MSG_LINETYPE_DISABLED;
extern const void* const _MSG_LINETYPE_NORMAL;
extern const void* const _MSG_LINETYPE_DOTTED;
extern const void* const _MSG_LINETYPE_SHADOW;
extern const void* const _MSG_LINETYPE_GLOW;
extern const void* const _MSG_HELP_LINETYPES;
extern const void* const _MSG_BUTTON_LABEL_FOLDER;
extern const void* const _MSG_BUTTON_SHORTCUT_FOLDER;
extern const void* const _MSG_WIN_TITLE_FOLDER_IMAGE;
extern const void* const _MSG_HELP_FOLDER_IMAGE;
extern const void* const _MSG_BUTTON_LABEL_FOLDERIMAGE;
extern const void* const _MSG_BUTTON_SHORTCUT_FOLDERIMAGE;
extern const void* const _MSG_HELP_FOLDERIMAGE;
extern const void* const _MSG_BUTTON_LABEL_INDENTWIDTH;
extern const void* const _MSG_BUTTON_SHORTCUT_INDENTWIDTH;
extern const void* const _MSG_HELP_INDENTWIDTH;
extern const void* const _MSG_BUTTON_LABEL_GLOW;
extern const void* const _MSG_BUTTON_SHORTCUT_GLOW;
extern const void* const _MSG_WIN_TITLE_GLOW_COLOR;
extern const void* const _MSG_HELP_GLOW_COLOR;

// substiting defines to directly use MSG_XXXXX strings
#define MSG_Space ((const void* const)1)
#define MSG_TAB_LAYOUT ((const void* const)&_MSG_TAB_LAYOUT)
#define MSG_GROUP_IMAGES_COLORS ((const void* const)&_MSG_GROUP_IMAGES_COLORS)
#define MSG_BUTTON_LABEL_CLOSED ((const void* const)&_MSG_BUTTON_LABEL_CLOSED)
#define MSG_BUTTON_SHORTCUT_CLOSED ((const void* const)&_MSG_BUTTON_SHORTCUT_CLOSED)
#define MSG_HELP_CLOSED_IMAGE ((const void* const)&_MSG_HELP_CLOSED_IMAGE)
#define MSG_WIN_TITLE_CLOSED_IMAGE ((const void* const)&_MSG_WIN_TITLE_CLOSED_IMAGE)
#define MSG_BUTTON_LABEL_LINES ((const void* const)&_MSG_BUTTON_LABEL_LINES)
#define MSG_BUTTON_SHORTCUT_LINES ((const void* const)&_MSG_BUTTON_SHORTCUT_LINES)
#define MSG_HELP_LINES_COLOR ((const void* const)&_MSG_HELP_LINES_COLOR)
#define MSG_WIN_TITLE_LINES_COLOR ((const void* const)&_MSG_WIN_TITLE_LINES_COLOR)
#define MSG_BUTTON_LABEL_OPEN ((const void* const)&_MSG_BUTTON_LABEL_OPEN)
#define MSG_BUTTON_SHORTCUT_OPEN ((const void* const)&_MSG_BUTTON_SHORTCUT_OPEN)
#define MSG_HELP_OPEN_IMAGE ((const void* const)&_MSG_HELP_OPEN_IMAGE)
#define MSG_WIN_TITLE_OPEN_IMAGE ((const void* const)&_MSG_WIN_TITLE_OPEN_IMAGE)
#define MSG_BUTTON_LABEL_SHADOW ((const void* const)&_MSG_BUTTON_LABEL_SHADOW)
#define MSG_BUTTON_SHORTCUT_SHADOW ((const void* const)&_MSG_BUTTON_SHORTCUT_SHADOW)
#define MSG_HELP_SHADOW_COLOR ((const void* const)&_MSG_HELP_SHADOW_COLOR)
#define MSG_WIN_TITLE_SHADOW_COLOR ((const void* const)&_MSG_WIN_TITLE_SHADOW_COLOR)
#define MSG_BUTTON_LABEL_SPECIAL ((const void* const)&_MSG_BUTTON_LABEL_SPECIAL)
#define MSG_BUTTON_SHORTCUT_SPECIAL ((const void* const)&_MSG_BUTTON_SHORTCUT_SPECIAL)
#define MSG_HELP_SPECIAL_IMAGE ((const void* const)&_MSG_HELP_SPECIAL_IMAGE)
#define MSG_WIN_TITLE_SPECIAL_IMAGE ((const void* const)&_MSG_WIN_TITLE_SPECIAL_IMAGE)
#define MSG_BUTTON_LABEL_DRAW ((const void* const)&_MSG_BUTTON_LABEL_DRAW)
#define MSG_BUTTON_SHORTCUT_DRAW ((const void* const)&_MSG_BUTTON_SHORTCUT_DRAW)
#define MSG_HELP_DRAW_COLOR ((const void* const)&_MSG_HELP_DRAW_COLOR)
#define MSG_WIN_TITLE_DRAW_COLOR ((const void* const)&_MSG_WIN_TITLE_DRAW_COLOR)
#define MSG_GROUP_STYLE ((const void* const)&_MSG_GROUP_STYLE)
#define MSG_CYCLE_LABEL_STYLE ((const void* const)&_MSG_CYCLE_LABEL_STYLE)
#define MSG_CYCLE_SHORTCUT_STYLE ((const void* const)&_MSG_CYCLE_SHORTCUT_STYLE)
#define MSG_HELP_STYLE ((const void* const)&_MSG_HELP_STYLE)
#define MSG_CYCLE_ITEM_STYLE_NORMAL ((const void* const)&_MSG_CYCLE_ITEM_STYLE_NORMAL)
#define MSG_CYCLE_ITEM_STYLE_INSERTED ((const void* const)&_MSG_CYCLE_ITEM_STYLE_INSERTED)
#define MSG_CYCLE_ITEM_STYLE_LINES ((const void* const)&_MSG_CYCLE_ITEM_STYLE_LINES)
#define MSG_CYCLE_ITEM_STYLE_WIN98 ((const void* const)&_MSG_CYCLE_ITEM_STYLE_WIN98)
#define MSG_CYCLE_ITEM_STYLE_MAC ((const void* const)&_MSG_CYCLE_ITEM_STYLE_MAC)
#define MSG_CYCLE_ITEM_STYLE_LINES3D ((const void* const)&_MSG_CYCLE_ITEM_STYLE_LINES3D)
#define MSG_CYCLE_ITEM_STYLE_WIN98PLUS ((const void* const)&_MSG_CYCLE_ITEM_STYLE_WIN98PLUS)
#define MSG_CYCLE_ITEM_STYLE_GLOW ((const void* const)&_MSG_CYCLE_ITEM_STYLE_GLOW)
#define MSG_BUTTON_LABEL_SPACE ((const void* const)&_MSG_BUTTON_LABEL_SPACE)
#define MSG_BUTTON_SHORTCUT_SPACE ((const void* const)&_MSG_BUTTON_SHORTCUT_SPACE)
#define MSG_HELP_SPACE ((const void* const)&_MSG_HELP_SPACE)
#define MSG_BUTTON_LABEL_REMEMBER ((const void* const)&_MSG_BUTTON_LABEL_REMEMBER)
#define MSG_BUTTON_SHORTCUT_REMEMBER ((const void* const)&_MSG_BUTTON_SHORTCUT_REMEMBER)
#define MSG_HELP_REMEMBER ((const void* const)&_MSG_HELP_REMEMBER)
#define MSG_BUTTON_LABEL_AUTOSCROLL ((const void* const)&_MSG_BUTTON_LABEL_AUTOSCROLL)
#define MSG_BUTTON_SHORTCUT_AUTOSCROLL ((const void* const)&_MSG_BUTTON_SHORTCUT_AUTOSCROLL)
#define MSG_HELP_AUTOSCROLL ((const void* const)&_MSG_HELP_AUTOSCROLL)
#define MSG_TAB_EXAMPLE ((const void* const)&_MSG_TAB_EXAMPLE)
#define MSG_HELP_LISTVIEW_EXAMPLE ((const void* const)&_MSG_HELP_LISTVIEW_EXAMPLE)
#define MSG_BUTTON_LABEL_EXPAND ((const void* const)&_MSG_BUTTON_LABEL_EXPAND)
#define MSG_BUTTON_SHORTCUT_EXPAND ((const void* const)&_MSG_BUTTON_SHORTCUT_EXPAND)
#define MSG_BUTTON_LABEL_COLLAPSE ((const void* const)&_MSG_BUTTON_LABEL_COLLAPSE)
#define MSG_BUTTON_SHORTCUT_COLLAPSE ((const void* const)&_MSG_BUTTON_SHORTCUT_COLLAPSE)
#define MSG_BUTTON_LABEL_LINETYPES ((const void* const)&_MSG_BUTTON_LABEL_LINETYPES)
#define MSG_BUTTON_SHORTCUT_LINETYPES ((const void* const)&_MSG_BUTTON_SHORTCUT_LINETYPES)
#define MSG_LINETYPE_DISABLED ((const void* const)&_MSG_LINETYPE_DISABLED)
#define MSG_LINETYPE_NORMAL ((const void* const)&_MSG_LINETYPE_NORMAL)
#define MSG_LINETYPE_DOTTED ((const void* const)&_MSG_LINETYPE_DOTTED)
#define MSG_LINETYPE_SHADOW ((const void* const)&_MSG_LINETYPE_SHADOW)
#define MSG_LINETYPE_GLOW ((const void* const)&_MSG_LINETYPE_GLOW)
#define MSG_HELP_LINETYPES ((const void* const)&_MSG_HELP_LINETYPES)
#define MSG_BUTTON_LABEL_FOLDER ((const void* const)&_MSG_BUTTON_LABEL_FOLDER)
#define MSG_BUTTON_SHORTCUT_FOLDER ((const void* const)&_MSG_BUTTON_SHORTCUT_FOLDER)
#define MSG_WIN_TITLE_FOLDER_IMAGE ((const void* const)&_MSG_WIN_TITLE_FOLDER_IMAGE)
#define MSG_HELP_FOLDER_IMAGE ((const void* const)&_MSG_HELP_FOLDER_IMAGE)
#define MSG_BUTTON_LABEL_FOLDERIMAGE ((const void* const)&_MSG_BUTTON_LABEL_FOLDERIMAGE)
#define MSG_BUTTON_SHORTCUT_FOLDERIMAGE ((const void* const)&_MSG_BUTTON_SHORTCUT_FOLDERIMAGE)
#define MSG_HELP_FOLDERIMAGE ((const void* const)&_MSG_HELP_FOLDERIMAGE)
#define MSG_BUTTON_LABEL_INDENTWIDTH ((const void* const)&_MSG_BUTTON_LABEL_INDENTWIDTH)
#define MSG_BUTTON_SHORTCUT_INDENTWIDTH ((const void* const)&_MSG_BUTTON_SHORTCUT_INDENTWIDTH)
#define MSG_HELP_INDENTWIDTH ((const void* const)&_MSG_HELP_INDENTWIDTH)
#define MSG_BUTTON_LABEL_GLOW ((const void* const)&_MSG_BUTTON_LABEL_GLOW)
#define MSG_BUTTON_SHORTCUT_GLOW ((const void* const)&_MSG_BUTTON_SHORTCUT_GLOW)
#define MSG_WIN_TITLE_GLOW_COLOR ((const void* const)&_MSG_WIN_TITLE_GLOW_COLOR)
#define MSG_HELP_GLOW_COLOR ((const void* const)&_MSG_HELP_GLOW_COLOR)

#endif /* NListtree_mcp_LOCALE_H */
