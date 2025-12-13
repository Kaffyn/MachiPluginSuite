$addonsPath = "c:\Users\bruno\Desktop\Games\MachiPluginSuite\addons"
Get-ChildItem -Path $addonsPath -Directory | ForEach-Object {
    $binPath = Join-Path $_.FullName "bin"
    if (Test-Path $binPath) {
        Write-Host "Cleaning $binPath..."
        Remove-Item -Path "$binPath\*" -Include *.dll,*.so,*.exp,*.lib,*.pdb -Force -Recurse
    }
}
Write-Host "Clean complete."
