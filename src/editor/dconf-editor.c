/* dconf-editor.c generated by valac 0.35.3.1-efc5, the Vala compiler
 * generated from dconf-editor.vala, do not modify */

/*
  This file is part of Dconf Editor

  Dconf Editor is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Dconf Editor is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Dconf Editor.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <glib/gi18n-lib.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "config.h"
#include <stdio.h>
#include <gdk/gdk.h>


#define TYPE_CONFIGURATION_EDITOR (configuration_editor_get_type ())
#define CONFIGURATION_EDITOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CONFIGURATION_EDITOR, ConfigurationEditor))
#define CONFIGURATION_EDITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CONFIGURATION_EDITOR, ConfigurationEditorClass))
#define IS_CONFIGURATION_EDITOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CONFIGURATION_EDITOR))
#define IS_CONFIGURATION_EDITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CONFIGURATION_EDITOR))
#define CONFIGURATION_EDITOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CONFIGURATION_EDITOR, ConfigurationEditorClass))

typedef struct _ConfigurationEditor ConfigurationEditor;
typedef struct _ConfigurationEditorClass ConfigurationEditorClass;
typedef struct _ConfigurationEditorPrivate ConfigurationEditorPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_DCONF_WINDOW (dconf_window_get_type ())
#define DCONF_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DCONF_WINDOW, DConfWindow))
#define DCONF_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DCONF_WINDOW, DConfWindowClass))
#define IS_DCONF_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DCONF_WINDOW))
#define IS_DCONF_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DCONF_WINDOW))
#define DCONF_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DCONF_WINDOW, DConfWindowClass))

typedef struct _DConfWindow DConfWindow;
typedef struct _DConfWindowClass DConfWindowClass;

struct _ConfigurationEditor {
	GtkApplication parent_instance;
	ConfigurationEditorPrivate * priv;
};

struct _ConfigurationEditorClass {
	GtkApplicationClass parent_class;
};

struct _ConfigurationEditorPrivate {
	GNotification* notification;
	guint notification_number;
};


static gpointer configuration_editor_parent_class = NULL;

GType configuration_editor_get_type (void) G_GNUC_CONST;
#define CONFIGURATION_EDITOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_CONFIGURATION_EDITOR, ConfigurationEditorPrivate))
enum  {
	CONFIGURATION_EDITOR_DUMMY_PROPERTY
};
static void configuration_editor_copy_cb (ConfigurationEditor* self, GSimpleAction* action, GVariant* gvariant);
static void _configuration_editor_copy_cb_gsimple_action_activate_callback (GSimpleAction* action, GVariant* parameter, gpointer self);
void configuration_editor_about_cb (ConfigurationEditor* self);
static void _configuration_editor_about_cb_gsimple_action_activate_callback (GSimpleAction* action, GVariant* parameter, gpointer self);
static void configuration_editor_quit_cb (ConfigurationEditor* self);
static void _configuration_editor_quit_cb_gsimple_action_activate_callback (GSimpleAction* action, GVariant* parameter, gpointer self);
gint configuration_editor_main (gchar** args, int args_length1);
ConfigurationEditor* configuration_editor_new (void);
ConfigurationEditor* configuration_editor_construct (GType object_type);
static gint configuration_editor_real_handle_local_options (GApplication* base, GVariantDict* options);
static void configuration_editor_real_startup (GApplication* base);
DConfWindow* dconf_window_new (void);
DConfWindow* dconf_window_construct (GType object_type);
GType dconf_window_get_type (void) G_GNUC_CONST;
static void configuration_editor_real_activate (GApplication* base);
void configuration_editor_copy (ConfigurationEditor* self, const gchar* text);
void configuration_editor_clean_copy_notification (ConfigurationEditor* self);
static gboolean __lambda4_ (ConfigurationEditor* self);
static gboolean ___lambda4__gsource_func (gpointer self);
static void configuration_editor_finalize (GObject * obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);

static const GOptionEntry CONFIGURATION_EDITOR_option_entries[2] = {{"version", 'v', 0, G_OPTION_ARG_NONE, NULL, N_ ("Print release version and exit"), NULL}, {}};
static const GActionEntry CONFIGURATION_EDITOR_action_entries[3] = {{"copy", _configuration_editor_copy_cb_gsimple_action_activate_callback, "s"}, {"about", _configuration_editor_about_cb_gsimple_action_activate_callback}, {"quit", _configuration_editor_quit_cb_gsimple_action_activate_callback}};

static void _configuration_editor_copy_cb_gsimple_action_activate_callback (GSimpleAction* action, GVariant* parameter, gpointer self) {
	configuration_editor_copy_cb ((ConfigurationEditor*) self, action, parameter);
}


static void _configuration_editor_about_cb_gsimple_action_activate_callback (GSimpleAction* action, GVariant* parameter, gpointer self) {
	configuration_editor_about_cb ((ConfigurationEditor*) self);
}


static void _configuration_editor_quit_cb_gsimple_action_activate_callback (GSimpleAction* action, GVariant* parameter, gpointer self) {
	configuration_editor_quit_cb ((ConfigurationEditor*) self);
}


gint configuration_editor_main (gchar** args, int args_length1) {
	gint result = 0;
	ConfigurationEditor* app;
	ConfigurationEditor* _tmp0_;
	gchar** _tmp1_;
	gint _tmp1__length1;
	gint _tmp2_;
	setlocale (LC_ALL, "");
	bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
	_tmp0_ = configuration_editor_new ();
	app = _tmp0_;
	_tmp1_ = args;
	_tmp1__length1 = args_length1;
	_tmp2_ = g_application_run ((GApplication*) app, _tmp1__length1, _tmp1_);
	result = _tmp2_;
	_g_object_unref0 (app);
	return result;
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
	return configuration_editor_main (argv, argc);
}


ConfigurationEditor* configuration_editor_construct (GType object_type) {
	ConfigurationEditor * self = NULL;
	self = (ConfigurationEditor*) g_object_new (object_type, "application-id", "ca.desrt.dconf-editor", "flags", G_APPLICATION_FLAGS_NONE, NULL);
	g_application_add_main_option_entries ((GApplication*) self, CONFIGURATION_EDITOR_option_entries);
	return self;
}


ConfigurationEditor* configuration_editor_new (void) {
	return configuration_editor_construct (TYPE_CONFIGURATION_EDITOR);
}


static gint configuration_editor_real_handle_local_options (GApplication* base, GVariantDict* options) {
	ConfigurationEditor * self;
	gint result = 0;
	GVariantDict* _tmp0_;
	gboolean _tmp1_;
	self = (ConfigurationEditor*) base;
	g_return_val_if_fail (options != NULL, 0);
	_tmp0_ = options;
	_tmp1_ = g_variant_dict_contains (_tmp0_, "version");
	if (_tmp1_) {
		FILE* _tmp2_;
		_tmp2_ = stdout;
		fprintf (_tmp2_, "%1$s %2$s\n", "dconf-editor", VERSION);
		result = EXIT_SUCCESS;
		return result;
	}
	result = -1;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void configuration_editor_real_startup (GApplication* base) {
	ConfigurationEditor * self;
	GtkCssProvider* css_provider;
	GtkCssProvider* _tmp0_;
	GdkScreen* screen;
	GdkScreen* _tmp1_;
	GdkScreen* _tmp2_;
	DConfWindow* _tmp3_;
	DConfWindow* _tmp4_;
	self = (ConfigurationEditor*) base;
	G_APPLICATION_CLASS (configuration_editor_parent_class)->startup ((GApplication*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_application_get_type (), GtkApplication));
	g_set_application_name (_ ("dconf Editor"));
	gtk_window_set_default_icon_name ("dconf-editor");
	g_action_map_add_action_entries ((GActionMap*) self, CONFIGURATION_EDITOR_action_entries, G_N_ELEMENTS (CONFIGURATION_EDITOR_action_entries), self);
	_tmp0_ = gtk_css_provider_new ();
	css_provider = _tmp0_;
	gtk_css_provider_load_from_resource (css_provider, "/ca/desrt/dconf-editor/ui/dconf-editor.css");
	_tmp1_ = gdk_screen_get_default ();
	_tmp2_ = _g_object_ref0 (_tmp1_);
	screen = _tmp2_;
	g_return_if_fail (screen != NULL);
	gtk_style_context_add_provider_for_screen (G_TYPE_CHECK_INSTANCE_CAST (screen, gdk_screen_get_type (), GdkScreen), (GtkStyleProvider*) css_provider, (guint) GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	_tmp3_ = dconf_window_new ();
	g_object_ref_sink (_tmp3_);
	_tmp4_ = _tmp3_;
	gtk_application_add_window ((GtkApplication*) self, (GtkWindow*) _tmp4_);
	_g_object_unref0 (_tmp4_);
	_g_object_unref0 (screen);
	_g_object_unref0 (css_provider);
}


static void configuration_editor_real_activate (GApplication* base) {
	ConfigurationEditor * self;
	GtkWindow* _tmp0_;
	self = (ConfigurationEditor*) base;
	_tmp0_ = gtk_application_get_active_window ((GtkApplication*) self);
	gtk_window_present (_tmp0_);
}


static void configuration_editor_copy_cb (ConfigurationEditor* self, GSimpleAction* action, GVariant* gvariant) {
	GVariant* _tmp0_;
	GVariant* _tmp1_;
	const gchar* _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (action != NULL);
	_tmp0_ = gvariant;
	if (_tmp0_ == NULL) {
		return;
	}
	_tmp1_ = gvariant;
	_tmp2_ = g_variant_get_string ((GVariant*) _tmp1_, NULL);
	configuration_editor_copy (self, _tmp2_);
}


static gboolean __lambda4_ (ConfigurationEditor* self) {
	gboolean result = FALSE;
	g_application_withdraw_notification ((GApplication*) self, "copy");
	self->priv->notification_number = (guint) 0;
	result = G_SOURCE_REMOVE;
	return result;
}


static gboolean ___lambda4__gsource_func (gpointer self) {
	gboolean result;
	result = __lambda4_ ((ConfigurationEditor*) self);
	return result;
}


void configuration_editor_copy (ConfigurationEditor* self, const gchar* text) {
	GdkDisplay* display;
	GdkDisplay* _tmp0_;
	GdkDisplay* _tmp1_;
	GdkDisplay* _tmp2_;
	GtkClipboard* clipboard;
	GdkDisplay* _tmp3_;
	GtkClipboard* _tmp4_;
	GtkClipboard* _tmp5_;
	GtkClipboard* _tmp6_;
	const gchar* _tmp7_;
	const gchar* _tmp8_;
	gint _tmp9_;
	gint _tmp10_;
	guint _tmp11_;
	GNotification* _tmp12_;
	const gchar* _tmp13_;
	GNotification* _tmp14_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	_tmp0_ = gdk_display_get_default ();
	_tmp1_ = _g_object_ref0 (_tmp0_);
	display = _tmp1_;
	_tmp2_ = display;
	if (_tmp2_ == NULL) {
		_g_object_unref0 (display);
		return;
	}
	_tmp3_ = display;
	_tmp4_ = gtk_clipboard_get_default (G_TYPE_CHECK_INSTANCE_CAST (_tmp3_, gdk_display_get_type (), GdkDisplay));
	_tmp5_ = _g_object_ref0 (_tmp4_);
	clipboard = _tmp5_;
	_tmp6_ = clipboard;
	_tmp7_ = text;
	_tmp8_ = text;
	_tmp9_ = strlen (_tmp8_);
	_tmp10_ = _tmp9_;
	gtk_clipboard_set_text (_tmp6_, _tmp7_, _tmp10_);
	configuration_editor_clean_copy_notification (self);
	_tmp11_ = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 30, ___lambda4__gsource_func, g_object_ref (self), g_object_unref);
	self->priv->notification_number = _tmp11_;
	_tmp12_ = self->priv->notification;
	_tmp13_ = text;
	g_notification_set_body (_tmp12_, _tmp13_);
	_tmp14_ = self->priv->notification;
	g_application_send_notification ((GApplication*) self, "copy", _tmp14_);
	_g_object_unref0 (clipboard);
	_g_object_unref0 (display);
}


void configuration_editor_clean_copy_notification (ConfigurationEditor* self) {
	guint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->notification_number;
	if (_tmp0_ > ((guint) 0)) {
		guint _tmp1_;
		g_application_withdraw_notification ((GApplication*) self, "copy");
		_tmp1_ = self->priv->notification_number;
		g_source_remove (_tmp1_);
		self->priv->notification_number = (guint) 0;
	}
}


void configuration_editor_about_cb (ConfigurationEditor* self) {
	gchar** authors;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar** _tmp2_;
	gint authors_length1;
	gint _authors_size_;
	GtkWindow* _tmp3_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup ("Robert Ancell");
	_tmp1_ = g_strdup ("Arnaud Bonatti");
	_tmp2_ = g_new0 (gchar*, 2 + 1);
	_tmp2_[0] = _tmp0_;
	_tmp2_[1] = _tmp1_;
	authors = _tmp2_;
	authors_length1 = 2;
	_authors_size_ = authors_length1;
	_tmp3_ = gtk_application_get_active_window ((GtkApplication*) self);
	gtk_show_about_dialog (_tmp3_, "program-name", _ ("dconf Editor"), "version", VERSION, "comments", _ ("Directly edit your entire configuration database"), "copyright", _ ("Copyright \xc2\xa9 2010-2014 – Canonical Ltd\n" \
"Copyright \xc2\xa9 2015-2016 – Arnaud Bonatti"), "license-type", GTK_LICENSE_GPL_3_0, "wrap-license", TRUE, "authors", authors, "translator-credits", _ ("translator-credits"), "logo-icon-name", "dconf-editor", NULL, NULL);
	authors = (_vala_array_free (authors, authors_length1, (GDestroyNotify) g_free), NULL);
}


static void configuration_editor_quit_cb (ConfigurationEditor* self) {
	GtkWindow* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = gtk_application_get_active_window ((GtkApplication*) self);
	gtk_widget_destroy ((GtkWidget*) _tmp0_);
	g_application_quit ((GApplication*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_application_get_type (), GtkApplication));
}


static void configuration_editor_class_init (ConfigurationEditorClass * klass) {
	configuration_editor_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (ConfigurationEditorPrivate));
	((GApplicationClass *) klass)->handle_local_options = configuration_editor_real_handle_local_options;
	((GApplicationClass *) klass)->startup = configuration_editor_real_startup;
	((GApplicationClass *) klass)->activate = configuration_editor_real_activate;
	G_OBJECT_CLASS (klass)->finalize = configuration_editor_finalize;
}


static void configuration_editor_instance_init (ConfigurationEditor * self) {
	GNotification* _tmp0_;
	self->priv = CONFIGURATION_EDITOR_GET_PRIVATE (self);
	_tmp0_ = g_notification_new (_ ("Copied to clipboard"));
	self->priv->notification = _tmp0_;
	self->priv->notification_number = (guint) 0;
}


static void configuration_editor_finalize (GObject * obj) {
	ConfigurationEditor * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_CONFIGURATION_EDITOR, ConfigurationEditor);
	_g_object_unref0 (self->priv->notification);
	G_OBJECT_CLASS (configuration_editor_parent_class)->finalize (obj);
}


GType configuration_editor_get_type (void) {
	static volatile gsize configuration_editor_type_id__volatile = 0;
	if (g_once_init_enter (&configuration_editor_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ConfigurationEditorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) configuration_editor_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ConfigurationEditor), 0, (GInstanceInitFunc) configuration_editor_instance_init, NULL };
		GType configuration_editor_type_id;
		configuration_editor_type_id = g_type_register_static (gtk_application_get_type (), "ConfigurationEditor", &g_define_type_info, 0);
		g_once_init_leave (&configuration_editor_type_id__volatile, configuration_editor_type_id);
	}
	return configuration_editor_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



