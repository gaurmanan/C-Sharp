Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

#User defined function for checking if a program returned an error code
#Call the following function after exectuing any exe
function Get-ExeExecutionError {
	if($LASTEXITCODE -ne 0)
	{	
		Write-Error "Error returned while executing an Exe"
		throw "Return Error"
	}
}

try
{
    $data = Read-Host "Please input string to encrypt."
    $key = ((65..90) + (97..122) + (48..57) | Get-Random -Count 32 | % {[char]$_}) -join ""
    Write-Host "Key: $key"
    Write-Host "Encryted string:"
    Enc.exe "$data" "$key"

	#############################################################################################
}

catch 
{
	$error[0].Exception.Message
	exit 1
}