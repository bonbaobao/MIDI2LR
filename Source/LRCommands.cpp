/*
  ==============================================================================

    LRCommands.cpp
    Created: 31 Jul 2015 10:21:12pm
    Author:  Parth, Jaffe

This file is part of MIDI2LR. Copyright 2015-2016 by Rory Jaffe.

MIDI2LR is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

MIDI2LR is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
MIDI2LR.  If not, see <http://www.gnu.org/licenses/>.
  ==============================================================================
*/
#include <unordered_map>
#include "LRCommands.h"
#include "CommandMap.h"

const std::vector<String> LRCommandList::General = {
    "Import Photos and Videos",
    "Export",
    "Primary Display Grid",
    "Increase Grid Size",
    "Decrease Grid Size",
    "Show Extras",
    "Show Badges",
    "Cycle Grid View Style",
    "Primary Display Loupe",
    "Primary Display Show Information",
    "Primary Display Cycle Info Display",
    "Primary Display Compare",
    "Swap Images",
    "Primary Display Survey",
    "Enable/Disable Zoom",
    "Zoom In",
    "Zoom In Some",
    "Zoom Out Some",
    "Zoom Out",
    "Show/Hide Toolbar",
    "Show/Hide Side Panels",
    "Show/Hide All Panels",
    "Select All",
    "Select None",
    "Add to Selection Left",
    "Add to Selection Right",
    "Select Only Active Photo",
    "Deselect Active Photo",
    "Select Flagged Photos",
    "Deselect Unflagged Photos",
    "Previous Selected Photo",
    "Next Selected Photo",
    "Next Photo",
    "Previous Photo",
    "Go Normal Mode",
    "Full Screen Hide Panels",
    "Full Screen Preview",
    "Cycle Lights Out",
    "Go Lights Out Dim",
    "HDR...",
    "HDR",
    "Panorama...",
    "Panorama",
    "Edit in Photoshop",
    "Edit in Other",
};

const std::vector<String> LRCommandList::Library = {
    "Show Library",
    "Add To Quick Collection",
    "Add to Quick Collection/Next",
    "Show Quick Collection",
    "Save Quick Collection...",
    "Clear Quick Collection",
    "Target Quick Collection",
    "Stack Photos",
    "Unstack Photos",
    "Toggle Stack",
    "Move to Stack Top",
    "Move Up in Stack",
    "Move Down in Stack",
    "Set Pick Flag",
    "Set Rejected Flag",
    "Unflagged",
    "0 Stars",
    "1 Star",
    "2 Stars",
    "3 Stars",
    "4 Stars",
    "5 Stars",
    "Increase Rating",
    "Decrease Rating",
    "Label Blue Enable/Disable",
    "Label Green Enable/Disable",
    "Label Red Enable/Disable",
    "Label Purple Enable/Disable",
    "Label Yellow Enable/Disable",
    "Rotate Left",
    "Rotate Right",
    "Delete",
    "Delete Rejected",
    "Remove from Catalog",
    "Trash Photo",
    "Primary Display People",
};

const std::vector<String> LRCommandList::Develop = {
    "Show Develop",
    "Copy Settings",
    "Paste Settings",
    "Paste Selected Settings",
    "Paste From Previous",
    "Match Exposures",
    "Create Virtual Copy",
    "Reset Settings",
    "Reset Last Modified",
    "Increase Last Modified",
    "Decrease Last Modified",
    "Undo",
    "Redo",
    "Primary Display Before/After Left/Right",
    "Primary Display Before/After Top/Bottom",
    "Primary Display Before",
    "Before/After",
    "Auto Tone",
    "Show Clipping",
    "Primary Display Loupe",
};

const std::vector<String> LRCommandList::BasicAdjustments = {
    "Show Basic Tone",
    "White Balance As Shot",
    "White Balance Auto",
    "White Balance Cloudy",
    "White Balance Daylight",
    "White Balance Flash",
    "White Balance Fluorescent",
    "White Balance Shade",
    "White Balance Tungsten",
    "Temperature",
    "Tint",
    "Exposure",
    "Contrast",
    "Highlights (Highlight Recovery in PV2003 and PV2010)",
    "Brightness",
    "Shadows (Fill Light in PV2003 and PV2010)",
    "Whites (no effect in PV2003 and PV2010)",
    "Blacks",
    "Clarity",
    "Vibrance",
    "Saturation",
    "Reset Temperature",
    "Reset Tint",
    "Reset Exposure",
    "Reset Contrast",
    "Reset Highlights",
    "Reset Shadows",
    "Reset Whites",
    "Reset Blacks",
    "Reset Clarity",
    "Reset Vibrance",
    "Reset Saturation",
};

const std::vector<String> LRCommandList::ToneCurve = {
    "Show Tone Curve",
    "Enable Tone Curve",
    "Dark Tones",
    "Light Tones",
    "Shadow Tones",
    "Highlight Tones",
    "Shadow Split",
    "Midtone Split",
    "Highlight Split",
    "Reset Dark Tones",
    "Reset Light Tones",
    "Reset Shadow Tones",
    "Reset Highlight Tones",
    "Reset Shadow Split",
    "Reset Midtone Split",
    "Reset Highlight Split",
};

const std::vector<String> LRCommandList::Mixer = {
    "Show Color Adjustments",
    "Enable Color Adjustments",
    "Saturation Adjustment Red",
    "Saturation Adjustment Orange",
    "Saturation Adjustment Yellow",
    "Saturation Adjustment Green",
    "Saturation Adjustment Aqua",
    "Saturation Adjustment Blue",
    "Saturation Adjustment Purple",
    "Saturation Adjustment Magenta",
    "Hue Adjustment Red",
    "Hue Adjustment Orange",
    "Hue Adjustment Yellow",
    "Hue Adjustment Green",
    "Hue Adjustment Aqua",
    "Hue Adjustment Blue",
    "Hue Adjustment Purple",
    "Hue Adjustment Magenta",
    "Luminance Adjustment Red",
    "Luminance Adjustment Orange",
    "Luminance Adjustment Yellow",
    "Luminance Adjustment Green",
    "Luminance Adjustment Aqua",
    "Luminance Adjustment Blue",
    "Luminance Adjustment Purple",
    "Luminance Adjustment Magenta",
    "Convert to Grayscale",
    "Enable Grayscale Mix",
    "Gray Mixer Red",
    "Gray Mixer Orange",
    "Gray Mixer Yellow",
    "Gray Mixer Green",
    "Gray Mixer Aqua",
    "Gray Mixer Blue",
    "Gray Mixer Purple",
    "Gray Mixer Magenta",
};

const std::vector<String> LRCommandList::ResetMixer = {
    "Reset Saturation Adjustment Red",
    "Reset Saturation Adjustment Orange",
    "Reset Saturation Adjustment Yellow",
    "Reset Saturation Adjustment Green",
    "Reset Saturation Adjustment Aqua",
    "Reset Saturation Adjustment Blue",
    "Reset Saturation Adjustment Purple",
    "Reset Saturation Adjustment Magenta",
    "Reset Hue Adjustment Red",
    "Reset Hue Adjustment Orange",
    "Reset Hue Adjustment Yellow",
    "Reset Hue Adjustment Green",
    "Reset Hue Adjustment Aqua",
    "Reset Hue Adjustment Blue",
    "Reset Hue Adjustment Purple",
    "Reset Hue Adjustment Magenta",
    "Reset Luminance Adjustment Red",
    "Reset Luminance Adjustment Orange",
    "Reset Luminance Adjustment Yellow",
    "Reset Luminance Adjustment Green",
    "Reset Luminance Adjustment Aqua",
    "Reset Luminance Adjustment Blue",
    "Reset Luminance Adjustment Purple",
    "Reset Luminance Adjustment Magenta",
    "Reset Gray Mixer Red",
    "Reset Gray Mixer Orange",
    "Reset Gray Mixer Yellow",
    "Reset Gray Mixer Green",
    "Reset Gray Mixer Aqua",
    "Reset Gray Mixer Blue",
    "Reset Gray Mixer Purple",
    "Reset Gray Mixer Magenta",
};

const std::vector<String> LRCommandList::SplitToning = {
    "Show Split Toning",
    "Enable Split Toning",
    "Shadow Hue",
    "Shadow Saturation",
    "Highlight Hue",
    "Highlight Saturation",
    "Split Toning Balance",
    "Reset Shadow Hue",
    "Reset Shadow Saturation",
    "Reset Highlight Hue",
    "Reset Highlight Saturation",
    "Reset Split Toning Balance",
};

const std::vector<String> LRCommandList::Detail = {
    "Show Detail",
    "Enable Detail",
    "Sharpness",
    "Sharpen Radius",
    "Sharpen Detail",
    "Sharpen Edge Masking",
    "Luminance Smoothing",
    "Luminance Detail",
    "Luminance Contrast",
    "Color Noise Reduction",
    "Color Noise Reduction Detail",
    "Color Noise Reduction Smoothness",
    "Reset Sharpness",
    "Reset Sharpen Radius",
    "Reset Sharpen Detail",
    "Reset Sharpen Edge Masking",
    "Reset Luminance Smoothing",
    "Reset Luminance Detail",
    "Reset Luminance Contrast",
    "Reset Color Noise Reduction",
    "Reset Color Noise Reduction Detail",
    "Reset Color Noise Reduction Smoothness",
};

const std::vector<String> LRCommandList::LensCorrections = {
    "Show Lens Corrections",
    "Enable Lens Corrections",
    "Perspective Correction Off",
    "Perspective Correction Auto",
    "Perspective Correction Level",
    "Perspective Correction Vertical",
    "Perspective Correction Full",
    "Reset Upright Settings",
    "Lens Profile Distortion Scale",
    "Lens Profile Chromatic Aberration Scale",
    "Lens Profile Vignetting Scale",
    "Reset Lens Profile Distortion Scale",
    "Reset Lens Profile Chromatic Aberration Scale",
    "Reset Lens Profile Vignetting Scale",
    "Defringe Purple Amount",
    "Defringe Purple Hue - Low",
    "Defringe Purple Hue - High",
    "Defringe Green Amount",
    "Defringe Green Hue - Low",
    "Defringe Green Hue - High",
    "Reset Defringe Purple Amount",
    "Reset Defringe Purple Hue - Low",
    "Reset Defringe Purple Hue - High",
    "Reset Defringe Green Amount",
    "Reset Defringe Green Hue - Low",
    "Reset Defringe Green Hue - High",
    "Lens Manual Distortion Amount",
    "Perspective Vertical",
    "Perspective Horizontal",
    "Perspective Rotate",
    "Perspective Scale",
    "Perspective Aspect",
    "Vignette Amount",
    "Vignette Midpoint",
    "Reset Lens Manual Distortion Amount",
    "Reset Perspective Vertical",
    "Reset Perspective Horizontal",
    "Reset Perspective Rotate",
    "Reset Perspective Scale",
    "Reset Perspective Aspect",
    "Reset Vignette Amount",
    "Reset Vignette Midpoint",
};

const std::vector<String> LRCommandList::Effects = {
    "Show Effects",
    "Enable Effects",
    "Dehaze Amount",
    "Post Crop Vignette Amount",
    "Post Crop Vignette Midpoint",
    "Post Crop Vignette Feather",
    "Post Crop Vignette Roundness",
    "Post Crop Vignette Style",
    "Post Crop Vignette Highlight Contrast",
    "Grain Amount",
    "Grain Size",
    "Grain Roughness",
    "Reset Dehaze Amount",
    "Reset Post Crop Vignette Amount",
    "Reset Post Crop Vignette Midpoint",
    "Reset Post Crop Vignette Feather",
    "Reset Post Crop Vignette Roundness",
    "Reset Post Crop Vignette Style",
    "Reset Post Crop Vignette Highlight Contrast",
    "Reset Grain Amount",
    "Reset Grain Size",
    "Reset Grain Roughness",
};

const std::vector<String> LRCommandList::Calibration = {
    "Show Calibration",
    "Enable Calibration",
    "Adobe Standard",
    "Camera Clear",
    "Camera Darker Skin Tone",
    "Camera Deep",
    "Camera Faithful",
    "Camera Flat",
    "Camera Landscape",
    "Camera Light",
    "Camera Lighter Skin Tone",
    "Camera Monochrome",
    "Camera Monotone",
    "Camera Muted",
    "Camera Natural",
    "Camera Neutral",
    "Camera Portrait",
    "Camera Positive Film",
    "Camera Standard",
    "Camera Vivid",
    "Camera Vivid Blue",
    "Camera Vivid Green",
    "Camera Vivid Red",
    "Shadow Tint Calibration",
    "Red Hue Calibration",
    "Red Saturation Calibration",
    "Green Hue Calibration",
    "Green Saturation Calibration",
    "Blue Hue Calibration",
    "Blue Saturation Calibration",
    "Reset Shadow Tint Calibration",
    "Reset Red Hue Calibration",
    "Reset Red Saturation Calibration",
    "Reset Green Hue Calibration",
    "Reset Green Saturation Calibration",
    "Reset Blue Hue Calibration",
    "Reset Blue Saturation Calibration",
};

const std::vector<String> LRCommandList::DevelopPresets = {
    "Develop Preset 1",
    "Develop Preset 2",
    "Develop Preset 3",
    "Develop Preset 4",
    "Develop Preset 5",
    "Develop Preset 6",
    "Develop Preset 7",
    "Develop Preset 8",
    "Develop Preset 9",
    "Develop Preset 10",
    "Develop Preset 11",
    "Develop Preset 12",
    "Develop Preset 13",
    "Develop Preset 14",
    "Develop Preset 15",
    "Develop Preset 16",
    "Develop Preset 17",
    "Develop Preset 18",
    "Develop Preset 19",
    "Develop Preset 20",
    "Develop Preset 21",
    "Develop Preset 22",
    "Develop Preset 23",
    "Develop Preset 24",
    "Develop Preset 25",
    "Develop Preset 26",
    "Develop Preset 27",
    "Develop Preset 28",
    "Develop Preset 29",
    "Develop Preset 30",
    "Develop Preset 31",
    "Develop Preset 32",
    "Develop Preset 33",
    "Develop Preset 34",
    "Develop Preset 35",
    "Develop Preset 36",
    "Develop Preset 37",
    "Develop Preset 38",
    "Develop Preset 39",
    "Develop Preset 40",
};

const std::vector<String> LRCommandList::LocalAdjustments = {
    "Show Graduated Filters",
    "Show Radial Filters",
    "Show Red-Eye Correction",
    "Show Spot Removal",
    "Show Brush Adjustments",
    "Increase Size",
    "Decrease Size",
    "Increase Feathering",
    "Decrease Feathering",
    "Local Adjustments Temp. (PV2012)",
    "Local Adjustments Tint (PV2012)",
    "Local Adjustments Exposure (PV2010 and PV2012)",
    "Local Adjustments Contrast (PV2010 and PV2012)",
    "Local Adjustments Highlights (PV2012)",
    "Local Adjustments Shadows (PV2012)",
    "Local Adjustments Whites (PV2012)",
    "Local Adjustments Blacks (PV2012)",
    "Local Adjustments Clarity (PV2010 and PV2012)",
    "Local Adjustments Dehaze (PV2012)",
    "Local Adjustments Saturation (PV2010 and PV2012)",
    "Local Adjustments Sharpness (PV2010 and PV2012)",
    "Local Adjustments Luminence Noise Reduction (PV2012)",
    "Local Adjustments Moire (PV2012)",
    "Local Adjustments Defringe (PV2012)",
    "Local Toning Luminance (PV2010)",
    "Reset Local Adjustments Temp. (PV2012)",
    "Reset Local Adjustments Tint (PV2012)",
    "Reset Local Adjustments Exposure (PV2010 and PV2012)",
    "Reset Local Adjustments Contrast (PV2010 and PV2012)",
    "Reset Local Adjustments Highlights (PV2012)",
    "Reset Local Adjustments Shadows (PV2012)",
    "Reset Local Adjustments Whites (PV2012)",
    "Reset Local Adjustments Blacks (PV2012)",
    "Reset Local Adjustments Clarity (PV2010 and PV2012)",
    "Reset Local Adjustments Dehaze (PV2012)",
    "Reset Local Adjustments Saturation (PV2010 and PV2012)",
    "Reset Local Adjustments Sharpness (PV2010 and PV2012)",
    "Reset Local Adjustments Luminence Noise Reduction (PV2012)",
    "Reset Local Adjustments Moire (PV2012)",
    "Reset Local Adjustments Defringe (PV2012)",
    "Reset Local Toning Luminance (PV2010)",
    "Enable Radial Filter",
    "Enable Graduated Filter",
    "Enable Brush Adjustments",
    "Enable Red-Eye",
    "Enable Spot Removal",
    "Reset Radial Filters",
    "Reset Graduated Filters",
    "Reset Brush Corrections",
    "Reset Red-Eye",
    "Reset Spot Removal",
};

const std::vector<String> LRCommandList::Crop = {
    "Straighten Angle",
    "Crop Angle",
    "Crop - Bottom",
    "Crop - Left",
    "Crop - Right",
    "Crop - Top",
    "Reset Crop",
    "Reset Straighten Angle",
    "Show Crop",
};

const std::vector<String> LRCommandList::ToolModulePanel = {
    "Show Loupe",
    "Show Map",
    "Show Book",
    "Show Slideshow",
    "Show Print",
    "Show Web",
};

const std::vector<String> LRCommandList::ViewModes = {
    "Secondary Display Loupe",
    "Secondary Display Live Loupe",
    "Secondary Display Locked Loupe",
    "Secondary Display Grid",
    "Secondary Display Compare",
    "Secondary Display Survey",
    "Secondary Display Slideshow",
    "Secondary Display Show",
};

const std::vector<String> LRCommandList::ProgramProfiles = {
    "Profile: 1",
    "Profile: 2",
    "Profile: 3",
    "Profile: 4",
    "Profile: 5",
    "Profile: 6",
    "Profile: 7",
    "Profile: 8",
    "Profile: 9",
    "Profile: 10",
};

const std::vector<String> LRCommandList::LRStringList = {
    "Unmapped",
    /* General */
    "KPImportImages",
    "KPExportImages",
    "ShoVwgrid",
    "KPIncreaseGridSize",
    "KPDecreaseGridSize",
    "KPShowExtras",
    "KPShowBadges",
    "KPCycleViewStyle",
    "ShoVwloupe",
    "ShoInfoLoupe",
    "ShoCycleInfoStyle",
    "ShoVwcompare",
    "KPSwapImages",
    "ShoVwsurvey",
    "ToggleZoomOffOn",
    "ZoomInLargeStep",
    "ZoomInSmallStep",
    "ZoomOutSmallStep",
    "ZoomOutLargeStep",
    "KPHideToolbar",
    "KPHidePanels",
    "KPHideAllPanels",
    "KPSelectAll",
    "KPSelectNone",
    "Select1Left",
    "Select1Right",
    "KPSelectActive",
    "KPDeselectActive",
    "KPSelectFlagged",
    "KPDeselectUnflagged",
    "KPPrevSelected",
    "KPNextSelected",
    "Next",
    "Prev",
    "KPGoNormalMode",
    "KPFullScrHidePanles",
    "KPFullScrPreview",
    "KPCycleLightsOut",
    "KPGoLightsOutDim",
    "KPMergeHDR",
    "KPMergeHDRnoDlg",
    "KPMergePano",
    "KPMergePanonoDlg",
    "KPEditInPhotoshop",
    "KPEditInOther",
    /* Library */
    "SwToMlibrary",
    "KPAddToQuickCollection",
    "KPAddToQuickCollectionAndNext",
    "KPShowQuickCollection",
    "KPSaveQuickCollection",
    "KPClearQuickCollection",
    "KPTargetQuickCollection",
    "KPGroupIntoStack",
    "KPUnstack",
    "KPExpandStack",
    "KPToTopStack",
    "KPUpInStack",
    "KPDnInStack",
    "Pick",
    "Reject",
    "RemoveFlag",
    "SetRating0",
    "SetRating1",
    "SetRating2",
    "SetRating3",
    "SetRating4",
    "SetRating5",
    "IncreaseRating",
    "DecreaseRating",
    "ToggleBlue",
    "ToggleGreen",
    "ToggleRed",
    "TogglePurple",
    "ToggleYellow",
    "KPRotateLeft",
    "KPRotateRight",
    "KPDelete",
    "KPDeleteRej",
    "KPRemoveFromCat",
    "KPTrash",
    "ShoVwpeople",
    /* Develop */
    "SwToMdevelop",
    "CopySettings",
    "PasteSettings",
    "PasteSelectedSettings",
    "KPPasteFromPrevious",
    "KPMatchExposures",
    "VirtualCopy",
    "ResetAll",
    "ResetLast",
    "IncrementLastDevelopParameter",
    "DecrementLastDevelopParameter",
    "Undo",
    "Redo",
    "ShoVwdevelop_before_after_horiz",
    "ShoVwdevelop_before_after_vert",
    "ShoVwdevelop_before",
    "KPBeforeAfter",
    "KPAutoTone",
    "KPClipping",
    "ShoVwdevelop_loupe",
    /* Basic Tone */
    "RevealPanelAdjust",
    "WhiteBalanceAs_Shot",
    "WhiteBalanceAuto",
    "WhiteBalanceCloudy",
    "WhiteBalanceDaylight",
    "WhiteBalanceFlash",
    "WhiteBalanceFluorescent",
    "WhiteBalanceShade",
    "WhiteBalanceTungsten",
    "Temperature",
    "Tint",
    "Exposure",
    "Contrast",
    "Highlights",
    "Brightness",
    "Shadows",
    "Whites",
    "Blacks",
    "Clarity",
    "Vibrance",
    "Saturation",
    "ResetTemperature",
    "ResetTint",
    "ResetExposure",
    "ResetContrast",
    "ResetHighlights",
    "ResetShadows",
    "ResetWhites",
    "ResetBlacks",
    "ResetClarity",
    "ResetVibrance",
    "ResetSaturation",
    /* Tone Curve */
    "RevealPanelTone",
    "EnableToneCurve",
    "ParametricDarks",
    "ParametricLights",
    "ParametricShadows",
    "ParametricHighlights",
    "ParametricShadowSplit",
    "ParametricMidtoneSplit",
    "ParametricHighlightSplit",
    "ResetParametricDarks",
    "ResetParametricLights",
    "ResetParametricShadows",
    "ResetParametricHighlights",
    "ResetParametricShadowSplit",
    "ResetParametricMidtoneSplit",
    "ResetParametricHighlightSplit",
    /* Color Adjustments */
    "RevealPanelMixer",
    "EnableColorAdjustments",
    "SaturationAdjustmentRed",
    "SaturationAdjustmentOrange",
    "SaturationAdjustmentYellow",
    "SaturationAdjustmentGreen",
    "SaturationAdjustmentAqua",
    "SaturationAdjustmentBlue",
    "SaturationAdjustmentPurple",
    "SaturationAdjustmentMagenta",
    "HueAdjustmentRed",
    "HueAdjustmentOrange",
    "HueAdjustmentYellow",
    "HueAdjustmentGreen",
    "HueAdjustmentAqua",
    "HueAdjustmentBlue",
    "HueAdjustmentPurple",
    "HueAdjustmentMagenta",
    "LuminanceAdjustmentRed",
    "LuminanceAdjustmentOrange",
    "LuminanceAdjustmentYellow",
    "LuminanceAdjustmentGreen",
    "LuminanceAdjustmentAqua",
    "LuminanceAdjustmentBlue",
    "LuminanceAdjustmentPurple",
    "LuminanceAdjustmentMagenta",
    "ConvertToGrayscale",
    "EnableGrayscaleMix",
    "GrayMixerRed",
    "GrayMixerOrange",
    "GrayMixerYellow",
    "GrayMixerGreen",
    "GrayMixerAqua",
    "GrayMixerBlue",
    "GrayMixerPurple",
    "GrayMixerMagenta",
    /* Reset Color Adjustments */
    "ResetSaturationAdjustmentRed",
    "ResetSaturationAdjustmentOrange",
    "ResetSaturationAdjustmentYellow",
    "ResetSaturationAdjustmentGreen",
    "ResetSaturationAdjustmentAqua",
    "ResetSaturationAdjustmentBlue",
    "ResetSaturationAdjustmentPurple",
    "ResetSaturationAdjustmentMagenta",
    "ResetHueAdjustmentRed",
    "ResetHueAdjustmentOrange",
    "ResetHueAdjustmentYellow",
    "ResetHueAdjustmentGreen",
    "ResetHueAdjustmentAqua",
    "ResetHueAdjustmentBlue",
    "ResetHueAdjustmentPurple",
    "ResetHueAdjustmentMagenta",
    "ResetLuminanceAdjustmentRed",
    "ResetLuminanceAdjustmentOrange",
    "ResetLuminanceAdjustmentYellow",
    "ResetLuminanceAdjustmentGreen",
    "ResetLuminanceAdjustmentAqua",
    "ResetLuminanceAdjustmentBlue",
    "ResetLuminanceAdjustmentPurple",
    "ResetLuminanceAdjustmentMagenta",
    "ResetGrayMixerRed",
    "ResetGrayMixerOrange",
    "ResetGrayMixerYellow",
    "ResetGrayMixerGreen",
    "ResetGrayMixerAqua",
    "ResetGrayMixerBlue",
    "ResetGrayMixerPurple",
    "ResetGrayMixerMagenta",
    /* Split Toning */
    "RevealPanelSplit",
    "EnableSplitToning",
    "SplitToningShadowHue",
    "SplitToningShadowSaturation",
    "SplitToningHighlightHue",
    "SplitToningHighlightSaturation",
    "SplitToningBalance",
    "ResetSplitToningShadowHue",
    "ResetSplitToningShadowSaturation",
    "ResetSplitToningHighlightHue",
    "ResetSplitToningHighlightSaturation",
    "ResetSplitToningBalance",
    /* Detail */
    "RevealPanelDetail",
    "EnableDetail",
    "Sharpness",
    "SharpenRadius",
    "SharpenDetail",
    "SharpenEdgeMasking",
    "LuminanceSmoothing",
    "LuminanceNoiseReductionDetail",
    "LuminanceNoiseReductionContrast",
    "ColorNoiseReduction",
    "ColorNoiseReductionDetail",
    "ColorNoiseReductionSmoothness",
    "ResetSharpness",
    "ResetSharpenRadius",
    "ResetSharpenDetail",
    "ResetSharpenEdgeMasking",
    "ResetLuminanceSmoothing",
    "ResetLuminanceNoiseReductionDetail",
    "ResetLuminanceNoiseReductionContrast",
    "ResetColorNoiseReduction",
    "ResetColorNoiseReductionDetail",
    "ResetColorNoiseReductionSmoothness",
    /* Lens Corrections */
    "RevealPanelLens",
    "EnableLensCorrections",
    "UprightOff",
    "UprightAuto",
    "UprightLevel",
    "UprightVertical",
    "UprightFull",
    "ResetPerspectiveUpright",
    "LensProfileDistortionScale",
    "LensProfileChromaticAberrationScale",
    "LensProfileVignettingScale",
    "ResetLensProfileDistortionScale",
    "ResetLensProfileChromaticAberrationScale",
    "ResetLensProfileVignettingScale",
    "DefringePurpleAmount",
    "DefringePurpleHueLo",
    "DefringePurpleHueHi",
    "DefringeGreenAmount",
    "DefringeGreenHueLo",
    "DefringeGreenHueHi",
    "ResetDefringePurpleAmount",
    "ResetDefringePurpleHueLo",
    "ResetDefringePurpleHueHi",
    "ResetDefringeGreenAmount",
    "ResetDefringeGreenHueLo",
    "ResetDefringeGreenHueHi",
    "LensManualDistortionAmount",
    "PerspectiveVertical",
    "PerspectiveHorizontal",
    "PerspectiveRotate",
    "PerspectiveScale",
    "PerspectiveAspect",
    "VignetteAmount",
    "VignetteMidpoint",
    "ResetLensManualDistortionAmount",
    "ResetPerspectiveVertical",
    "ResetPerspectiveHorizontal",
    "ResetPerspectiveRotate",
    "ResetPerspectiveScale",
    "ResetPerspectiveAspect",
    "ResetVignetteAmount",
    "ResetVignetteMidpoint",
    /* Effects */
    "RevealPanelEffects",
    "EnableEffects",
    "Dehaze",
    "PostCropVignetteAmount",
    "PostCropVignetteMidpoint",
    "PostCropVignetteFeather",
    "PostCropVignetteRoundness",
    "PostCropVignetteStyle",
    "PostCropVignetteHighlightContrast",
    "GrainAmount",
    "GrainSize",
    "GrainFrequency",
    "ResetDehaze",
    "ResetPostCropVignetteAmount",
    "ResetPostCropVignetteMidpoint",
    "ResetPostCropVignetteFeather",
    "ResetPostCropVignetteRoundness",
    "ResetPostCropVignetteStyle",
    "ResetPostCropVignetteHighlightContrast",
    "ResetGrainAmount",
    "ResetGrainSize",
    "ResetGrainFrequency",
    /* Calibration */
    "RevealPanelCalibrate",
    "EnableCalibration",
    "Profile_Adobe_Standard",
    "Profile_Camera_Clear",
    "Profile_Camera_Darker_Skin_Tone",
    "Profile_Camera_Deep",
    "Profile_Camera_Faithful",
    "Profile_Camera_Flat",
    "Profile_Camera_Landscape",
    "Profile_Camera_Light",
    "Profile_Camera_Lighter_Skin_Tone",
    "Profile_Camera_Monochrome",
    "Profile_Camera_Monotone",
    "Profile_Camera_Muted",
    "Profile_Camera_Natural",
    "Profile_Camera_Neutral",
    "Profile_Camera_Portrait",
    "Profile_Camera_Positive_Film",
    "Profile_Camera_Standard",
    "Profile_Camera_Vivid",
    "Profile_Camera_Vivid_Blue",
    "Profile_Camera_Vivid_Green",
    "Profile_Camera_Vivid_Red",
    "ShadowTint",
    "RedHue",
    "RedSaturation",
    "GreenHue",
    "GreenSaturation",
    "BlueHue",
    "BlueSaturation",
    "ResetShadowTint",
    "ResetRedHue",
    "ResetRedSaturation",
    "ResetGreenHue",
    "ResetGreenSaturation",
    "ResetBlueHue",
    "ResetBlueSaturation",
    /* Develop Presets */
    "Preset_1",
    "Preset_2",
    "Preset_3",
    "Preset_4",
    "Preset_5",
    "Preset_6",
    "Preset_7",
    "Preset_8",
    "Preset_9",
    "Preset_10",
    "Preset_11",
    "Preset_12",
    "Preset_13",
    "Preset_14",
    "Preset_15",
    "Preset_16",
    "Preset_17",
    "Preset_18",
    "Preset_19",
    "Preset_20",
    "Preset_21",
    "Preset_22",
    "Preset_23",
    "Preset_24",
    "Preset_25",
    "Preset_26",
    "Preset_27",
    "Preset_28",
    "Preset_29",
    "Preset_30",
    "Preset_31",
    "Preset_32",
    "Preset_33",
    "Preset_34",
    "Preset_35",
    "Preset_36",
    "Preset_37",
    "Preset_38",
    "Preset_39",
    "Preset_40",
    /* Local Adjustments */
    "GraduatedFilter",
    "RadialFilter",
    "RedEye",
    "SpotRemoval",
    "AdjustmentBrush",
    "KPIncreaseSize",
    "KPDecreaseSize",
    "KPIncreaseFeather",
    "KPDecreaseFeather",
    "local_Temperature",
    "local_Tint",
    "local_Exposure",
    "local_Contrast",
    "local_Highlights",
    "local_Shadows",
    "local_Whites2012",
    "local_Blacks2012",
    "local_Clarity",
    "local_Dehaze",
    "local_Saturation",
    "local_Sharpness",
    "local_LuminanceNoise",
    "local_Moire",
    "local_Defringe",
    "local_ToningLuminance",
    "Resetlocal_Temperature",
    "Resetlocal_Tint",
    "Resetlocal_Exposure",
    "Resetlocal_Contrast",
    "Resetlocal_Highlights",
    "Resetlocal_Shadows",
    "Resetlocal_Whites2012",
    "Resetlocal_Blacks2012",
    "Resetlocal_Clarity",
    "Resetlocal_Dehaze",
    "Resetlocal_Saturation",
    "Resetlocal_Sharpness",
    "Resetlocal_LuminanceNoise",
    "Resetlocal_Moire",
    "Resetlocal_Defringe",
    "Resetlocal_ToningLuminance",
    "EnableCircularGradientBasedCorrections",
    "EnableGradientBasedCorrections",
    "EnablePaintBasedCorrections",
    "EnableRedEye",
    "EnableRetouch",
    "ResetCircGrad",
    "ResetGradient",
    "ResetBrushing",
    "ResetRedeye",
    "ResetSpotRem",
    /* Crop */
    "straightenAngle",
    "CropAngle",
    "CropBottom",
    "CropLeft",
    "CropRight",
    "CropTop",
    "ResetCrop",
    "ResetstraightenAngle",
    "CropOverlay",
    /* Select Tools, Modules and Panels */
    "Loupe",
    "SwToMmap",
    "SwToMbook",
    "SwToMslideshow",
    "SwToMprint",
    "SwToMweb",
    /* View Modes */
    "ShoScndVwloupe",
    "ShoScndVwlive_loupe",
    "ShoScndVwlocked_loupe",
    "ShoScndVwgrid",
    "ShoScndVwcompare",
    "ShoScndVwsurvey",
    "ShoScndVwslideshow",
    "ToggleScreenTwo",
    /* Profiles */
    "profile1",
    "profile2",
    "profile3",
    "profile4",
    "profile5",
    "profile6",
    "profile7",
    "profile8",
    "profile9",
    "profile10",
};

const std::vector<String> LRCommandList::NextPrevProfile = {
  "Previous Profile",
  "Next Profile",
};

int LRCommandList::getIndexOfCommand(const String& command)
{
    static std::unordered_map<String, int> indexMap;

    // better to check for empty then lenght, as empty has a constant run time behavior.
    if (indexMap.empty())
    {
        int idx = 0;
        for (auto &str : LRStringList)
            indexMap[str] = idx++;

        for (auto &str : NextPrevProfile)
            indexMap[str] = idx++;
    }

    return indexMap[command];

}