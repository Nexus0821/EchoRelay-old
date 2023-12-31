﻿using EchoRelay.App.Settings;
using EchoRelay.Core.Server;
using EchoRelay.Core.Server.Storage;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EchoRelay.CLI
{
    public static class Constants
    {
        public static string SettingsFile => Path.Combine(Environment.CurrentDirectory, "settings.json");
        public static string DatabaseFolder => Path.Combine(Environment.CurrentDirectory, "database");

        public static AppSettings? AppSettings => AppSettings.Load(SettingsFile);
        public static ServerStorage Storage { get; set; }
        public static Server Server { get; set; }
    }
}
