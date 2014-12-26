/* gtkplotarray - 3d scientific plots widget for gtk+
 * Copyright 1999-2001  Adrian E. Feiguin <feiguin@ifir.edu.ar>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GTK_PLOT_ARRAY_H__
#define __GTK_PLOT_ARRAY_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GTK_TYPE_PLOT_ARRAY_LIST        	(gtk_plot_array_list_get_type ())
#define GTK_PLOT_ARRAY_LIST(obj)        	(G_TYPE_CHECK_INSTANCE_CAST (obj, GTK_TYPE_PLOT_ARRAY_LIST, GtkPlotArrayList))
#define GTK_PLOT_ARRAY_LIST_CLASS(klass) 	(G_TYPE_CHECK_CLASS_CAST (klass, GTK_TYPE_PLOT_ARRAY_LIST, GtkPlotArrayListClass))
#define GTK_IS_PLOT_ARRAY_LIST(obj)     	(G_TYPE_CHECK_INSTANCE_TYPE (obj, GTK_TYPE_PLOT_ARRAY_LIST))
#define GTK_IS_PLOT_ARRAY_LIST_CLASS(obj)     	(G_CHECK_CLASS_TYPE (obj, GTK_TYPE_PLOT_ARRAY_LIST))

#define GTK_TYPE_PLOT_ARRAY        		(gtk_plot_array_get_type ())
#define GTK_PLOT_ARRAY(obj)        		(G_TYPE_CHECK_INSTANCE_CAST (obj, GTK_TYPE_PLOT_ARRAY, GtkPlotArray))
#define GTK_PLOT_ARRAY_CLASS(klass) 		(G_TYPE_CHECK_CLASS_CAST (klass, GTK_TYPE_PLOT_ARRAY, GtkPlotArrayClass))
#define GTK_IS_PLOT_ARRAY(obj)     		(G_TYPE_CHECK_INSTANCE_TYPE (obj, GTK_TYPE_PLOT_ARRAY))
#define GTK_IS_PLOT_ARRAY_CLASS(obj)     	(G_CHECK_CLASS_TYPE (obj, GTK_TYPE_PLOT_ARRAY))

typedef struct _GtkPlotArrayList          GtkPlotArrayList;
typedef struct _GtkPlotArrayListClass     GtkPlotArrayListClass;
typedef struct _GtkPlotArray             GtkPlotArray;
typedef struct _GtkPlotArrayClass        GtkPlotArrayClass;

typedef union
{
  gdouble *data_double;
  gfloat *data_float;
  gint *data_int;
  gboolean *data_bool;
  gchar **data_string;
  gpointer *data_pointer;
} GtkPlotArrayArg;

/**
 * GtkPlotArrayList:
 *
 * The GtkPlotArrayList struct contains only private data.
 * It should only be accessed through the functions described below.
 */
struct _GtkPlotArrayList
{
 /*< private >*/
  GObject object;

  GList *arrays;
};

struct _GtkPlotArrayListClass
{
  GObjectClass parent_class;
};

/**
 * GtkPlotArray:
 *
 * The GtkPlotArray struct contains only private data.
 * It should only be accessed through the functions described below.
 */
struct _GtkPlotArray
{
  GObject object;

  gchar *name;
  gchar *label;
  gchar *description;

  GtkPlotArrayArg data;
  GType type;
  gboolean own_data;
  gint size;

  gboolean required;
  gboolean independent;

  gdouble scale;
};

struct _GtkPlotArrayClass
{
  GObjectClass parent_class;
};


GType		gtk_plot_array_get_type		(void);
GObject*	gtk_plot_array_new		(const gchar *name, 
						 gpointer array,
						 gint size,
						 GType type,
						 gboolean own_data);
void		gtk_plot_array_set		(GtkPlotArray *array,
						 gpointer data_array,
						 gint size,
						 GType type); 
void		gtk_plot_array_set_label	(GtkPlotArray *array,
						 const gchar *label);
void		gtk_plot_array_set_description	(GtkPlotArray *array,
						 const gchar *desc);
void	 	gtk_plot_array_set_scale	(GtkPlotArray *array,
						 gdouble scale);
void	 	gtk_plot_array_set_required	(GtkPlotArray *array,
						 gboolean required);
void	 	gtk_plot_array_set_independent	(GtkPlotArray *array,
						 gboolean independent);
GType		gtk_plot_array_get_data_type	(GtkPlotArray *array);
const gchar *	gtk_plot_array_get_name		(GtkPlotArray *array);
const gchar *	gtk_plot_array_get_label	(GtkPlotArray *array);
const gchar *	gtk_plot_array_get_description	(GtkPlotArray *array);
gboolean	gtk_plot_array_required		(GtkPlotArray *array);
gboolean	gtk_plot_array_independent	(GtkPlotArray *array);
gdouble 	gtk_plot_array_get_scale	(GtkPlotArray *array);
gint		gtk_plot_array_get_size		(GtkPlotArray *array);
gfloat*		gtk_plot_array_get_float	(GtkPlotArray *array);
gdouble*	gtk_plot_array_get_double	(GtkPlotArray *array);
gint*		gtk_plot_array_get_int		(GtkPlotArray *array);
gboolean*	gtk_plot_array_get_bool		(GtkPlotArray *array);
gchar**		gtk_plot_array_get_string	(GtkPlotArray *array);
gpointer*	gtk_plot_array_get_pointer	(GtkPlotArray *array);
void		gtk_plot_array_free		(GtkPlotArray *array);
						
GType		gtk_plot_array_list_get_type	(void);
GObject*	gtk_plot_array_list_new		(void);
void		gtk_plot_array_list_add		(GtkPlotArrayList *set,
						 GtkPlotArray *array);
void		gtk_plot_array_list_remove	(GtkPlotArrayList *set,
						 GtkPlotArray *array);
GtkPlotArray*	gtk_plot_array_list_get		(GtkPlotArrayList *set,
						 const gchar *name);
void		gtk_plot_array_list_clear	(GtkPlotArrayList *set);

G_END_DECLS


#endif /* __GTK_PLOT_ARRAY_H__ */
