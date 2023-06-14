#!/bin/sh
ansible-galaxy collection install ansible.posix
ansible-galaxy collection install community.general
defaults write com.apple.dock autohide-delay -float 0; defaults write com.apple.dock autohide-time-modifier -float 0.3;killall Dock
sudo defaults write /Library/Preferences/SystemConfiguration/com.apple.DiskArbitration.diskarbitrationd.plist DADisableEjectNotification -bool YES && sudo pkill diskarbitrationd
env CGO_ENABLED=0 go install -ldflags="-s -w" github.com/gokcehan/lf@latest
defaults write com.knollsoft.Rectangle screenEdgeGapTop -int 0
