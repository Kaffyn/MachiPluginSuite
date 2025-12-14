$addonsPath = "c:\Users\bruno\Desktop\Games\MachiPluginSuite\addons"
Get-ChildItem -Path $addonsPath -Directory | ForEach-Object {
    $binPath = Join-Path $_.FullName "bin"
    if (Test-Path $binPath) {
        Write-Host "Removing $binPath..."
        Remove-Item -Path $binPath -Recurse -Force
    }
}
Write-Host "Clean complete."
