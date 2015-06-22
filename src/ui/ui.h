/*
 * ui.h
 *
 * Copyright (C) 2012 - 2015 James Booth <boothj5@gmail.com>
 *
 * This file is part of Profanity.
 *
 * Profanity is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Profanity is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Profanity.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give permission to
 * link the code of portions of this program with the OpenSSL library under
 * certain conditions as described in each individual source file, and
 * distribute linked combinations including the two.
 *
 * You must obey the GNU General Public License in all respects for all of the
 * code used other than OpenSSL. If you modify file(s) with this exception, you
 * may extend this exception to your version of the file(s), but you are not
 * obligated to do so. If you do not wish to do so, delete this exception
 * statement from your version. If you delete this exception statement from all
 * source files in the program, then also delete it here.
 *
 */

#ifndef UI_UI_H
#define UI_UI_H

#include "ui/win_types.h"
#include "muc.h"

#define NO_ME           1
#define NO_DATE         2
#define NO_EOL          4
#define NO_COLOUR_FROM  8
#define NO_COLOUR_DATE  16

// ui startup and control
void ui_init(void);
void ui_load_colours(void);
void ui_update(void);
void ui_close(void);
void ui_redraw(void);
void ui_resize(void);
GSList* ui_get_chat_recipients(void);
void ui_switch_win(ProfWin *window);
void ui_sigwinch_handler(int sig);

void ui_gone_secure(const char * const barejid, gboolean trusted);
void ui_gone_insecure(const char * const barejid);
void ui_trust(const char * const barejid);
void ui_untrust(const char * const barejid);
void ui_smp_recipient_initiated(const char * const barejid);
void ui_smp_recipient_initiated_q(const char * const barejid, const char *question);

void ui_smp_successful(const char * const barejid);
void ui_smp_unsuccessful_sender(const char * const barejid);
void ui_smp_unsuccessful_receiver(const char * const barejid);
void ui_smp_aborted(const char * const barejid);

void ui_smp_answer_success(const char * const barejid);
void ui_smp_answer_failure(const char * const barejid);

void ui_otr_authenticating(const char * const barejid);
void ui_otr_authetication_waiting(const char * const recipient);

void ui_handle_otr_error(const char * const barejid, const char * const message);

unsigned long ui_get_idle_time(void);
void ui_reset_idle_time(void);
ProfPrivateWin* ui_new_private_win(const char * const fulljid);
ProfChatWin* ui_new_chat_win(const char * const barejid);
void ui_print_system_msg_from_recipient(const char * const barejid, const char *message);
gint ui_unread(void);
void ui_close_connected_win(int index);
int ui_close_all_wins(void);
int ui_close_read_wins(void);

// current window actions
void ui_current_print_line(const char * const msg, ...);
void ui_current_print_formatted_line(const char show_char, int attrs, const char * const msg, ...);
void ui_current_error_line(const char * const msg);
void ui_win_error_line(ProfWin *window, const char * const msg);

win_type_t ui_win_type(int index);
void ui_close_win(int index);
int ui_win_unread(int index);
char * ui_ask_password(void);

void ui_handle_stanza(const char * const msg);

// ui events
void ui_contact_online(char *barejid, Resource *resource, GDateTime *last_activity);
void ui_contact_typing(const char * const barejid, const char * const resource);
void ui_incoming_msg(ProfChatWin *chatwin, const char * const resource,  const char * const message, GTimeVal *tv_stamp, gboolean win_created);
void ui_incoming_private_msg(const char * const fulljid, const char * const message, GTimeVal *tv_stamp);
void ui_message_receipt(const char * const barejid, const char * const id);

void ui_disconnected(void);
void ui_recipient_gone(const char * const barejid, const char * const resource);

void ui_outgoing_chat_msg(ProfChatWin *chatwin, const char * const message, char *id);
void ui_outgoing_chat_msg_carbon(const char * const barejid, const char * const message);
void ui_outgoing_private_msg(ProfPrivateWin *privwin, const char * const message);

void ui_room_join(const char * const roomjid, gboolean focus);
void ui_switch_to_room(const char * const roomjid);

void ui_room_role_change(const char * const roomjid, const char * const role, const char * const actor,
    const char * const reason);
void ui_room_affiliation_change(const char * const roomjid, const char * const affiliation, const char * const actor,
    const char * const reason);
void ui_room_role_and_affiliation_change(const char * const roomjid, const char * const role,
    const char * const affiliation, const char * const actor, const char * const reason);
void ui_room_occupant_role_change(const char * const roomjid, const char * const nick, const char * const role,
    const char * const actor, const char * const reason);
void ui_room_occupant_affiliation_change(const char * const roomjid, const char * const nick, const char * const affiliation,
    const char * const actor, const char * const reason);
void ui_room_occupant_role_and_affiliation_change(const char * const roomjid, const char * const nick, const char * const role,
    const char * const affiliation, const char * const actor, const char * const reason);
void ui_room_roster(const char * const roomjid, GList *occupants, const char * const presence);
void ui_room_history(const char * const roomjid, const char * const nick,
    GTimeVal tv_stamp, const char * const message);
void ui_room_message(const char * const roomjid, const char * const nick,
    const char * const message);
void ui_room_subject(const char * const roomjid, const char * const nick, const char * const subject);
void ui_room_requires_config(const char * const roomjid);
void ui_room_destroy(const char * const roomjid);
void ui_show_room_info(ProfMucWin *mucwin);
void ui_show_room_role_list(ProfMucWin *mucwin, muc_role_t role);
void ui_show_room_affiliation_list(ProfMucWin *mucwin, muc_affiliation_t affiliation);
void ui_handle_room_info_error(const char * const roomjid, const char * const error);
void ui_show_room_disco_info(const char * const roomjid, GSList *identities, GSList *features);
void ui_room_destroyed(const char * const roomjid, const char * const reason, const char * const new_jid,
    const char * const password);
void ui_room_kicked(const char * const roomjid, const char * const actor, const char * const reason);
void ui_room_member_kicked(const char * const roomjid, const char * const nick, const char * const actor,
    const char * const reason);
void ui_room_banned(const char * const roomjid, const char * const actor, const char * const reason);
void ui_room_member_banned(const char * const roomjid, const char * const nick, const char * const actor,
    const char * const reason);
void ui_leave_room(const char * const roomjid);
void ui_room_broadcast(const char * const roomjid,
    const char * const message);
void ui_room_member_offline(const char * const roomjid, const char * const nick);
void ui_room_member_online(const char * const roomjid, const char * const nick, const char * const roles,
    const char * const affiliation, const char * const show, const char * const status);
void ui_room_member_nick_change(const char * const roomjid,
    const char * const old_nick, const char * const nick);
void ui_room_nick_change(const char * const roomjid, const char * const nick);
void ui_room_member_presence(const char * const roomjid,
    const char * const nick, const char * const show, const char * const status);
void ui_room_update_occupants(const char * const roomjid);
void ui_room_show_occupants(const char * const roomjid);
void ui_room_hide_occupants(const char * const roomjid);
void ui_show_roster(void);
void ui_hide_roster(void);
void ui_roster_add(const char * const barejid, const char * const name);
void ui_roster_remove(const char * const barejid);
void ui_contact_already_in_group(const char * const contact, const char * const group);
void ui_contact_not_in_group(const char * const contact, const char * const group);
void ui_group_added(const char * const contact, const char * const group);
void ui_group_removed(const char * const contact, const char * const group);
void ui_chat_win_contact_online(PContact contact, Resource *resource, GDateTime *last_activity);
void ui_chat_win_contact_offline(PContact contact, char *resource, char *status);
void ui_contact_offline(char *barejid, char *resource, char *status);
void ui_handle_recipient_not_found(const char * const recipient, const char * const err_msg);
void ui_handle_recipient_error(const char * const recipient, const char * const err_msg);
void ui_handle_error(const char * const err_msg);
void ui_clear_win_title(void);
void ui_goodbye_title(void);
void ui_handle_room_join_error(const char * const roomjid, const char * const err);
void ui_handle_room_configuration(const char * const roomjid, DataForm *form);
void ui_handle_room_configuration_form_error(const char * const roomjid, const char * const message);
void ui_handle_room_config_submit_result(const char * const roomjid);
void ui_handle_room_config_submit_result_error(const char * const roomjid, const char * const message);
void ui_handle_room_affiliation_list_error(const char * const roomjid, const char * const affiliation,
    const char * const error);
void ui_handle_room_affiliation_list(const char * const roomjid, const char * const affiliation, GSList *jids);
void ui_handle_room_affiliation_set_error(const char * const roomjid, const char * const jid,
    const char * const affiliation, const char * const error);
void ui_handle_room_role_set_error(const char * const roomjid, const char * const nick, const char * const role,
    const char * const error);
void ui_handle_room_role_list_error(const char * const roomjid, const char * const role, const char * const error);
void ui_handle_room_role_list(const char * const roomjid, const char * const role, GSList *nicks);
void ui_handle_room_kick_error(const char * const roomjid, const char * const nick, const char * const error);
void ui_show_form(ProfMucConfWin *confwin);
void ui_show_form_field(ProfWin *window, DataForm *form, char *tag);
void ui_show_form_help(ProfMucConfWin *confwin);
void ui_show_form_field_help(ProfMucConfWin *confwin, char *tag);
void ui_show_lines(ProfWin *window, const gchar** lines);
void ui_redraw_all_room_rosters(void);
void ui_show_all_room_rosters(void);
void ui_hide_all_room_rosters(void);
gboolean ui_chat_win_exists(const char * const barejid);

gboolean ui_tidy_wins(void);
void ui_prune_wins(void);
gboolean ui_swap_wins(int source_win, int target_win);

void ui_page_up(void);
void ui_page_down(void);
void ui_subwin_page_up(void);
void ui_subwin_page_down(void);
void ui_clear_win(ProfWin *window);

void ui_auto_away(void);
void ui_end_auto_away(void);
void ui_titlebar_presence(contact_presence_t presence);
void ui_handle_login_account_success(ProfAccount *account);
void ui_update_presence(const resource_presence_t resource_presence,
    const char * const message, const char * const show);
void ui_about(void);
void ui_statusbar_new(const int win);

char* ui_readline(void);
void ui_input_clear(void);
void ui_input_nonblocking(gboolean);
void ui_write(char *line, int offset);

void ui_invalid_command_usage(const char * const usage, void (*setting_func)(void));

void ui_create_xmlconsole_win(void);
gboolean ui_xmlconsole_exists(void);
void ui_open_xmlconsole_win(void);

gboolean ui_win_has_unsaved_form(int num);

void ui_inp_history_append(char *inp);

// console window actions
void cons_show(const char * const msg, ...);
void cons_about(void);
void cons_help(void);
void cons_navigation_help(void);
void cons_prefs(void);
void cons_show_ui_prefs(void);
void cons_show_desktop_prefs(void);
void cons_show_chat_prefs(void);
void cons_show_log_prefs(void);
void cons_show_presence_prefs(void);
void cons_show_connection_prefs(void);
void cons_show_otr_prefs(void);
void cons_show_pgp_prefs(void);
void cons_show_account(ProfAccount *account);
void cons_debug(const char * const msg, ...);
void cons_show_time(void);
void cons_show_word(const char * const word);
void cons_show_error(const char * const cmd, ...);
void cons_show_contacts(GSList * list);
void cons_show_roster(GSList * list);
void cons_show_roster_group(const char * const group, GSList * list);
void cons_show_wins(void);
void cons_show_status(const char * const barejid);
void cons_show_info(PContact pcontact);
void cons_show_caps(const char * const fulljid, resource_presence_t presence);
void cons_show_themes(GSList *themes);
void cons_show_aliases(GList *aliases);
void cons_show_login_success(ProfAccount *account);
void cons_show_software_version(const char * const jid,
    const char * const presence, const char * const name,
    const char * const version, const char * const os);
void cons_show_account_list(gchar **accounts);
void cons_show_room_list(GSList *room, const char * const conference_node);
void cons_show_bookmarks(const GList *list);
void cons_show_disco_items(GSList *items, const char * const jid);
void cons_show_disco_info(const char *from, GSList *identities, GSList *features);
void cons_show_room_invite(const char * const invitor, const char * const room,
    const char * const reason);
void cons_check_version(gboolean not_available_msg);
void cons_show_typing(const char * const barejid);
void cons_show_incoming_message(const char * const short_from, const int win_index);
void cons_show_room_invites(GSList *invites);
void cons_show_received_subs(void);
void cons_show_sent_subs(void);
void cons_alert(void);
void cons_theme_setting(void);
void cons_resource_setting(void);
void cons_privileges_setting(void);
void cons_beep_setting(void);
void cons_flash_setting(void);
void cons_splash_setting(void);
void cons_encwarn_setting(void);
void cons_vercheck_setting(void);
void cons_occupants_setting(void);
void cons_roster_setting(void);
void cons_presence_setting(void);
void cons_wrap_setting(void);
void cons_winstidy_setting(void);
void cons_time_setting(void);
void cons_mouse_setting(void);
void cons_statuses_setting(void);
void cons_titlebar_setting(void);
void cons_notify_setting(void);
void cons_show_desktop_prefs(void);
void cons_states_setting(void);
void cons_outtype_setting(void);
void cons_intype_setting(void);
void cons_gone_setting(void);
void cons_history_setting(void);
void cons_carbons_setting(void);
void cons_receipts_setting(void);
void cons_log_setting(void);
void cons_chlog_setting(void);
void cons_grlog_setting(void);
void cons_autoaway_setting(void);
void cons_reconnect_setting(void);
void cons_autoping_setting(void);
void cons_priority_setting(void);
void cons_autoconnect_setting(void);
void cons_inpblock_setting(void);
void cons_show_contact_online(PContact contact, Resource *resource, GDateTime *last_activity);
void cons_show_contact_offline(PContact contact, char *resource, char *status);
void cons_theme_colours(void);

// status bar
void status_bar_inactive(const int win);
void status_bar_active(const int win);
void status_bar_new(const int win);
void status_bar_set_all_inactive(void);

// roster window
void rosterwin_roster(void);

// occupants window
void occupantswin_occupants(const char * const room);

// window interface
ProfWin* win_create_console(void);
ProfWin* win_create_xmlconsole(void);
ProfWin* win_create_chat(const char * const barejid);
ProfWin* win_create_muc(const char * const roomjid);
ProfWin* win_create_muc_config(const char * const title, DataForm *form);
ProfWin* win_create_private(const char * const fulljid);

void win_update_virtual(ProfWin *window);
void win_free(ProfWin *window);
int win_unread(ProfWin *window);
void win_resize(ProfWin *window);
void win_hide_subwin(ProfWin *window);
void win_show_subwin(ProfWin *window);
void win_refresh_without_subwin(ProfWin *window);
void win_refresh_with_subwin(ProfWin *window);
void win_print(ProfWin *window, const char show_char, GTimeVal *tstamp, int flags, theme_item_t theme_item, const char * const from, const char * const message);
void win_vprint(ProfWin *window, const char show_char, GTimeVal *tstamp, int flags, theme_item_t theme_item, const char * const from, const char * const message, ...);
char* win_get_title(ProfWin *window);
void win_show_occupant(ProfWin *window, Occupant *occupant);
void win_show_occupant_info(ProfWin *window, const char * const room, Occupant *occupant);
void win_show_contact(ProfWin *window, PContact contact);
void win_show_info(ProfWin *window, PContact contact);
void win_println(ProfWin *window, const char * const message);

// desktop notifier actions
void notifier_initialise(void);
void notifier_uninit(void);

void notify_typing(const char * const handle);
void notify_message(ProfWin *window, const char * const name, const char * const text);
void notify_room_message(const char * const handle, const char * const room,
    int win, const char * const text);
void notify_remind(void);
void notify_invite(const char * const from, const char * const room,
    const char * const reason);
void notify_subscription(const char * const from);

#endif
