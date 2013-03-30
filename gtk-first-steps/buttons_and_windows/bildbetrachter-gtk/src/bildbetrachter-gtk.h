/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * bildbetrachter-gtk.h
 * Copyright (C) 2013 sevenonlinez <>
 * 
 * bildbetrachter-gtk is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * bildbetrachter-gtk is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _BILDBETRACHTER_GTK_
#define _BILDBETRACHTER_GTK_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define BILDBETRACHTER_GTK_TYPE_APPLICATION             (bildbetrachter_gtk_get_type ())
#define BILDBETRACHTER_GTK_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), BILDBETRACHTER_GTK_TYPE_APPLICATION, Bildbetrachtergtk))
#define BILDBETRACHTER_GTK_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), BILDBETRACHTER_GTK_TYPE_APPLICATION, BildbetrachtergtkClass))
#define BILDBETRACHTER_GTK_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BILDBETRACHTER_GTK_TYPE_APPLICATION))
#define BILDBETRACHTER_GTK_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), BILDBETRACHTER_GTK_TYPE_APPLICATION))
#define BILDBETRACHTER_GTK_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), BILDBETRACHTER_GTK_TYPE_APPLICATION, BildbetrachtergtkClass))

typedef struct _BildbetrachtergtkClass BildbetrachtergtkClass;
typedef struct _Bildbetrachtergtk Bildbetrachtergtk;
typedef struct _BildbetrachtergtkPrivate BildbetrachtergtkPrivate;

struct _BildbetrachtergtkClass
{
	GtkApplicationClass parent_class;
};

struct _Bildbetrachtergtk
{
	GtkApplication parent_instance;

	BildbetrachtergtkPrivate *priv;

};

GType bildbetrachter_gtk_get_type (void) G_GNUC_CONST;
Bildbetrachtergtk *bildbetrachter_gtk_new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */

