// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
  ==============================================================================

    CommandMenu.cpp

This file is part of MIDI2LR. Copyright 2015 by Rory Jaffe.

MIDI2LR is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

MIDI2LR is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
MIDI2LR.  If not, see <http://www.gnu.org/licenses/>.
  ==============================================================================
*/
#include <gsl/gsl>
#include "CommandMenu.h"
#include "CCoptions.h"
#include "CommandMap.h"
#include "LRCommands.h"
#include "PWoptions.h"

CommandMenu::CommandMenu(const rsj::MidiMessageId& message)
    : juce::TextButton{"Unmapped"},
      menus_({"Keyboard Shortcuts for User", "Library filter", "General", "Library", "Develop",
          "Basic", "Tone Curve", "HSL / Color / B&W", "Reset HSL / Color / B&W", "Split Toning",
          "Detail", "Lens Corrections", "Transform", "Effects", "Camera Calibration",
          "Develop Presets", "Keywords", "Local Adjustments", "Crop",
          "Go to Tool, Module, or Panel", "Secondary Display", "Profiles", "Next/Prev Profile"}),
      menu_entries_({LrCommandList::KeyShortcuts, LrCommandList::Filters, LrCommandList::General,
          LrCommandList::Library, LrCommandList::Develop, LrCommandList::BasicAdjustments,
          LrCommandList::ToneCurve, LrCommandList::Mixer, LrCommandList::ResetMixer,
          LrCommandList::SplitToning, LrCommandList::Detail, LrCommandList::LensCorrections,
          LrCommandList::Transform, LrCommandList::Effects, LrCommandList::Calibration,
          LrCommandList::DevelopPresets, LrCommandList::Keywords, LrCommandList::LocalAdjustments,
          LrCommandList::Crop, LrCommandList::ToolModulePanel, LrCommandList::SecondaryDisplay,
          LrCommandList::ProgramProfiles, LrCommandList::NextPrevProfile}),
      message_{message}
{
}

void CommandMenu::Init(CommandMap* map_command) noexcept
{
   command_map_ = map_command;
}

void CommandMenu::SetMsg(const rsj::MidiMessageId& message) noexcept
{
   message_ = message;
}

void CommandMenu::SetSelectedItem(size_t index)
{
   selected_item_ = index;
   if (index - 1 < LrCommandList::LrStringList.size())
      setButtonText(LrCommandList::LrStringList.at(index - 1));
   else
      setButtonText(
          LrCommandList::NextPrevProfile.at(index - 1 - LrCommandList::LrStringList.size()));
}

void CommandMenu::clicked(const juce::ModifierKeys& modifiers)
{
   if (modifiers.isPopupMenu()) {
      switch (message_.msg_id_type) {
      case rsj::MsgIdEnum::kCc: {
         CCoptions ccopt;
         ccopt.BindToControl(
             gsl::narrow_cast<short>(message_.channel - 1), // convert 1-based to 0-based
             gsl::narrow_cast<short>(message_.controller));
         juce::DialogWindow::showModalDialog(
             "Adjust CC dialog", &ccopt, nullptr, juce::Colour::fromRGB(0xFF, 0xFF, 0xFF), true);
         break;
      }
      case rsj::MsgIdEnum::kPitchBend: {
         PWoptions pwopt;
         pwopt.BindToControl(
             gsl::narrow_cast<short>(message_.channel - 1)); // convert 1-based to 0 based
         juce::DialogWindow::showModalDialog(
             "Adjust PW dialog", &pwopt, nullptr, juce::Colour::fromRGB(0xFF, 0xFF, 0xFF), true);
         break;
      }
      default:
          /* do nothing for other types of controllers */;
      }
   }
   else {
      size_t index = 1;
      auto submenu_tick_set = false;
      juce::PopupMenu main_menu;
      main_menu.addItem(gsl::narrow_cast<int>(index), "Unmapped", true,
          submenu_tick_set = index == selected_item_);
      index++;
      // add each submenu
      for (size_t menu_index = 0; menu_index < menus_.size(); ++menu_index) {
         juce::PopupMenu sub_menu;
         for (const auto& command : menu_entries_.at(menu_index)) {
            auto already_mapped = false;
            if (index - 1 < LrCommandList::LrStringList.size() && command_map_)
               already_mapped = command_map_->CommandHasAssociatedMessage(
                   LrCommandList::LrStringList.at(index - 1));

            // add each submenu entry, ticking the previously selected entry and
            // disabling a previously mapped entry
            if (already_mapped)
               sub_menu.addColouredItem(gsl::narrow_cast<int>(index), command, juce::Colours::red,
                   true, index == selected_item_);
            else
               sub_menu.addItem(
                   gsl::narrow_cast<int>(index), command, true, index == selected_item_);

            index++;
         }
         // set whether or not the submenu is ticked (true if one of the submenu's
         // entries is selected)
         main_menu.addSubMenu(menus_.at(menu_index), sub_menu, true, nullptr,
             selected_item_ < index && !submenu_tick_set);
         submenu_tick_set |= selected_item_ < index && !submenu_tick_set;
      }

      const auto result = gsl::narrow_cast<size_t>(main_menu.show());
      if (result && command_map_) {
         // user chose a different command, remove previous command mapping
         // associated to this menu
         if (selected_item_ < std::numeric_limits<size_t>::max())
            command_map_->RemoveMessage(message_);
         if (result - 1 < LrCommandList::LrStringList.size())
            setButtonText(LrCommandList::LrStringList.at(result - 1));
         else
            setButtonText(
                LrCommandList::NextPrevProfile.at(result - 1 - LrCommandList::LrStringList.size()));
         selected_item_ = result;
         // Map the selected command to the CC
         command_map_->AddCommandforMessage(result - 1, message_);
      }
   }
}