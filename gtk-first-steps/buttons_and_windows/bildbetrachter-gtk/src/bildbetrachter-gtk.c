/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * bildbetrachter-gtk.c
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
#include "bildbetrachter-gtk.h"

#include <glib/gi18n.h>



/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/bildbetrachter_gtk.ui" */
#define UI_FILE "src/bildbetrachter_gtk.ui"
#define TOP_WINDOW "window"


G_DEFINE_TYPE (Bildbetrachtergtk, bildbetrachter_gtk, GTK_TYPE_APPLICATION);


/* Define the private structure in the .c file */
#define BILDBETRACHTER_GTK_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), BILDBETRACHTER_GTK_TYPE_APPLICATION, BildbetrachtergtkPrivate))

struct _BildbetrachtergtkPrivate
{
	/* ANJUTA: Widgets declaration for bildbetrachter_gtk.ui - DO NOT REMOVE */
};


/* Create a new window loading a file */
static void
bildbetrachter_gtk_new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;

	GtkBuilder *builder;
	GError* error = NULL;

	BildbetrachtergtkPrivate *priv = BILDBETRACHTER_GTK_GET_PRIVATE(app);

	/* Load UI from file */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_critical ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, app);

	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, TOP_WINDOW));
        if (!window)
        {
		g_critical ("Widget \"%s\" is missing in file %s.",
				TOP_WINDOW,
				UI_FILE);
        }

	
	/* ANJUTA: Widgets initialization for bildbetrachter_gtk.ui - DO NOT REMOVE */

	g_object_unref (builder);
	
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	if (file != NULL)
	{
		/* TODO: Add code here to open the file in the new window */
	}
	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
bildbetrachter_gtk_activate (GApplication *application)
{
	bildbetrachter_gtk_new_window (application, NULL);
}

static void
bildbetrachter_gtk_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		bildbetrachter_gtk_new_window (application, files[i]);
}

static void
bildbetrachter_gtk_init (Bildbetrachtergtk *object)
{

}

static void
bildbetrachter_gtk_finalize (GObject *object)
{
	G_OBJECT_CLASS (bildbetrachter_gtk_parent_class)->finalize (object);
}

static void
bildbetrachter_gtk_class_init (BildbetrachtergtkClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = bildbetrachter_gtk_activate;
	G_APPLICATION_CLASS (klass)->open = bildbetrachter_gtk_open;

	g_type_class_add_private (klass, sizeof (BildbetrachtergtkPrivate));

	G_OBJECT_CLASS (klass)->finalize = bildbetrachter_gtk_finalize;
}

Bildbetrachtergtk *
bildbetrachter_gtk_new (void)
{
	g_type_init ();

	return g_object_new (bildbetrachter_gtk_get_type (),
	                     "application-id", "org.gnome.bildbetrachter_gtk",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

