﻿using EchoRelay.Core.ConsoleUtils;
using System.Diagnostics;

namespace EchoRelay.Core.Game
{
    /// <summary>
    /// Launches the game with different configurable roles/settings.
    /// </summary>
    public abstract class GameLauncher
    {
        public static bool Launch(string executableFilePath, LaunchRole role = LaunchRole.Client, bool windowed = false, bool spectatorStream = false, bool moderator = false, bool noOVR = false, bool headless = false, List<string>? additionalArgs = null)
        {
            // Create a list of arguments
            List<string> args = additionalArgs ?? new List<string>();

            // Add any role related arguments (client role = no CLI argument here)
            switch(role)
            {
                case LaunchRole.Server:
                    args.Add("-server");
                    break;

                case LaunchRole.Offline:
                    args.Add("-offline");
                    break;
            }

            // Add our flags
            if (windowed)
                args.Add("-windowed");
            if (spectatorStream)
                args.Add("-spectatorstream");
            if (moderator)
                args.Add("-moderator");
            if (noOVR)
                args.Add("-noovr");
            if (headless)
            {
                args.Add("-headless");
                args.Add("-nosymbollookup");
                args.Add("-fixedtimestep");
            }

            ConsoleLogger.LogMessage(LogType.Info, "(GameLauncher) Launching Echo Arena as {0}, with {1} argument(s)\n\t\tFile Path: {2}\n\t\tArguments: {3}", role, args.Count, executableFilePath, string.Join(" ", args));

            // Start the process with our provided arguments.
            return Process.Start(executableFilePath, args) != null;
        }

        #region Enums
        /// <summary>
        /// Describes the type of launch that should occur. A client, server, or offline mode.
        /// </summary>
        public enum LaunchRole : int
        {
            Client = 0,
            Server = 1,
            Offline = 2,
        }
        #endregion
    }
}
