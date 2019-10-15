#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 * A catch-all file for configuring various bugfixes and other settings
 * (maybe eventually) in SM64
 */

// Bug Fixes
// --| Categories
/// Turn on bug fixes for really bad, C standard breaking code. This is
/// enabled automatically when building with non-IDO compilers, or if
/// NON_MATCHING is set.
#if !defined(__sgi) || defined(NON_MATCHING)
#define BUGFIXES_CRITICAL 1
#else
#define BUGFIXES_CRITICAL 0
#endif

// --| US Version Nintendo Bug Fixes
/// Fixes bug where obtaining over 999 coins sets the number of lives to 999 (or -25)
#define BUGFIX_MAX_LIVES (0 || VERSION_US || VERSION_EU)
/// Fixes bug where the Boss music won't fade out after defeating King Bob-omb
#define BUGFIX_KING_BOB_OMB_FADE_MUSIC (0 || VERSION_US || VERSION_EU)
/// Fixes bug in Bob-Omb Battlefield where entering a warp stops the Koopa race music
#define BUGFIX_KOOPA_RACE_MUSIC (0 || VERSION_US || VERSION_EU)
/// Fixes bug where Piranha Plants do not reset their action state when the
/// player exits their activation radius.
#define BUGFIX_PIRANHA_PLANT_STATE_RESET (0 || VERSION_US || VERSION_EU)
/// Fixes bug where sleeping Piranha Plants damage players that bump into them
#define BUGFIX_PIRANHA_PLANT_SLEEP_DAMAGE (0 || VERSION_US || VERSION_EU)
/// Fixes bug where it shows a star when you grab a key in bowser battle stages
#define BUGFIX_STAR_BOWSER_KEY (0 || VERSION_US || VERSION_EU)

// --| Goddard / Mario Head Bug Fixes
/// Goddard left out important and necessary return statements; this puts them back in
#define BUGFIX_GODDARD_MISSING_RETURN (0 || BUGFIXES_CRITICAL)
/// It seems that Goddard only declared, not prototyped some functions. This lead to
/// incorrect promotion of floats to doubles.
#define BUGFIX_GODDARD_BAD_DECLARATIONS (0 || BUGFIXES_CRITICAL)

// Screen Size Defines
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

// Border Height Define for NTSC Versions
#define BORDER_HEIGHT 8

#endif
