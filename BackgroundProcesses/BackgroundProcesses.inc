[Rainmeter]

[Variables]

;----------------------------------------------------
; # # ADD BACKGROUND PROCESSES BELOW # # # # # # # #
; # # Measures that run even when the app isn't open
;----------------------------------------------------

;----------------------------------------------------------------------
; Example # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
; Updates the top bar when CPU temperature changes
; 
; UpdateDivider=10 rechecks the temperature every 10 seconds
; Recommended this number be no lower than 10 to prevent high CPU usage
;----------------------------------------------------------------------

;[MeasureCPUTemp]
;Measure=Plugin
;Plugin=CoreTemp
;CoreTempType=Temperature
;CoreTempIndex=0
;OnChangeAction=[!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
;UpdateDivider=10

[MeasureNetwork]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfoData=BEST
RegExpSubstitute=1
Substitute="^(.*)\.(.*)\.(.*)\.(.*)$":"\1"
DynamicVariables=1 
OnChangeAction=[!UpdateMeasure "VPNStatus"]

[VPNStatus]
Measure=Calc
Formula=[MeasureNetwork]
IfBelowValue = 11
IfBelowAction=[!SetVariable VPNOnOff "1" "Droptop\DropdownBar"][!WriteKeyValue Variables VPNOnOff "1" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!Redraw]
IfAboveValue = 11
IfAboveAction=[!SetVariable VPNOnOff "0" "Droptop\DropdownBar"][!WriteKeyValue Variables VPNOnOff "0" "#SKINSPATH#Droptop Community Apps\Apps\VPN_Status-Mike_Boynton\Variables\Variables.inc"][!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!Redraw]
DynamicVariables=1
UpdateDivider=-1
OnUpdateAction=[!UpdateMeterGroup CustomAppButton "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!Redraw]

;[MeasureLocation]
;Measure=WebParser
;UserAgent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67
;URL=https://www.iplocation.net/
;RegExp=(?siU)<th>IP Location<\/th>[\s]{1,30}[\r\n | \n]<td>(.*)[\s]{1,30}(.*)[\S]{1,2}<a href=.*"
;Flags=ForceReload | NoCacheWrite | Resync
;OnConnectErrorAction=[!SetOption 2Status Text "Unable to get location data"]
;OnRegExpErrorAction=[!SetOption 2Status Text "Unable to get location data"]
;;FinishAction=[!SetOption 2Status Text "%1 %2"]
;FinishAction=[!SetOption 2Status Text "[MeasureCity] [MeasureRegion]" "Droptop Community Apps\Apps\VPN_Status-Mike_Boynton"]
;Group=Location

;[MeasureCity]
;Measure=Webparser
;URL=[MeasureLocation]
;StringIndex=1
;Group=Location

;[MeasureRegion]
;Measure=Webparser
;URL=[MeasureLocation]
;StringIndex=2
;Group=Location
;Substitute="&nbsp;":"","&nbs":""

