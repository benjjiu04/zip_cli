$directorio_actual = $PWD
$directorio_programa = "$directorio_actual\zip_cli.exe"


if (Test-Path -Path $directorio_programa){

    [Environment]::SetEnvironmentVariable("Path", [Environment]::GetEnvironmentVariable("Path", "User") + $directorio_programa, "User")
   
    Write-Host "zip_cli.exe añadido a PATH. ahora puedes invocarlo desde cualquier lado con 'zip_cli'`n"
    Write-Host "si luego desea borrarlo de path escriba 'SystemPropertiesAdvanced' en powershell o CMD luego presione el boton 'variables de entorno'`n"
    Write-Host "luego presione en Path y busque la ruta en la que esté zip_cli y eliminelo."
}
else{
    Write-Host "el script debe de estar junto al ejecutable del programa."
}
