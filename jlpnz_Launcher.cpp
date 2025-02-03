using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Controls;

namespace JNLP_Launcher
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void LaunchButton_Click(object sender, RoutedEventArgs e)
        {
            string url = UrlTextBox.Text;
            if (string.IsNullOrEmpty(url))
            {
                MessageBox.Show("Please enter a URL");
                return;
            }

            try
            {
                Process.Start(url);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error launching JNLP: " + ex.Message);
            }
        }
    }
}