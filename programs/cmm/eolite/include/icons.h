_ini icons_ini = { "/sys/File managers/icons.ini", NULL };

void DrawIconByExtension(dword file_path, extension, xx, yy, fairing_color)
{
	char BYTE_HEAD_FILE[4];
	char ext[512];
	int i;
	dword icon_n;
	dword selected_image;
	dword default_image;

	if (big_icons) {
		icons_ini.section = "icons32";
		selected_image = icons32_selected.image;
		default_image = icons32_default.image;
	}
	else {
		icons_ini.section = "icons16";
		selected_image = icons16_selected.image;
		default_image = icons16_default.image;
	}

	if (extension)
	{
		strcpy(#ext, extension);
		strlwr(#ext);
		icon_n = icons_ini.GetInt(#ext, 2);
	} 
	else if (file_path)
	{
			ReadFile(0,4,#BYTE_HEAD_FILE,file_path);
			IF(DSDWORD[#BYTE_HEAD_FILE]=='KCPK')||(DSDWORD[#BYTE_HEAD_FILE]=='UNEM') 
				icon_n = icons_ini.GetInt("kex", 2);
	}
	if (fairing_color==col_selec)
	{
		img_draw stdcall(selected_image, xx, yy, icon_size, icon_size, 0, icon_n*icon_size);
		if (!big_icons) IconFairing(icon_n, xx, yy, fairing_color);
	}
	else 
	{
		img_draw stdcall(default_image, xx, yy, icon_size, icon_size, 0, icon_n*icon_size);
	}
}


void IconFairing(dword filenum, x,y, color)
{
	//0 = folder
	//22 = forder with up arrow
	if (filenum == 0) || (filenum == 22)
	{
		DrawBar(x+7,y+1,8,2,color);
		DrawBar(x,y+14,15,2,color);
		PutPixel(x,y+1,color);
		PutPixel(x+6,y+1,color);
		PutPixel(x+14,y+3,color);
		PutPixel(x,y+13,color);
		PutPixel(x+14,y+13,color);
	}
	if (filenum == 22) PutPixel(x+10,y+2,0x1A7B17); //green arrow part
}
