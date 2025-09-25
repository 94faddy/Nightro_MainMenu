modded class LoadingScreen
{
	ref TStringArray MyFuckingLoadingScreenArray = {
		"Nightro_MainMenu\\data\\nt_loading_bgs.edds"};

	override void Show()
	{		
		string preel = MyFuckingLoadingScreenArray.GetRandomElement();
		m_ImageWidgetBackground.LoadMaskTexture("Nightro_MainMenu/data/ls_mask.paa");
		m_ImageWidgetBackground.LoadImageFile(0, preel);   
        m_ImageLogoMid.Show(false);
		m_ImageLogoCorner.Show(false);	    	
		m_ModdedWarning.Show(false); // Show / Hide - Modded version warning // 1.17 OK
		super.Show();
	}
}


modded class LoginTimeBase extends UIScriptedMenu
{
	ref TStringArray MyFuckingLoadingScreenArray = {
		"Nightro_MainMenu\\data\\nt_loading_bgs.edds"};

    override void Show()
    {
        super.Show();
        if (layoutRoot)
        {
            string preel = MyFuckingLoadingScreenArray.GetRandomElement();
            ImageWidget background = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background"));
            background.LoadImageFile(0, preel);  
        }
    }
}


modded class LoginQueueBase extends UIScriptedMenu
{
	ref TStringArray MyFuckingLoadingScreenArray = {
		"Nightro_MainMenu\\data\\nt_loading_bgs.edds"};

    override void Show()
    {
        super.Show();
        if (layoutRoot)
        {
            string preel = MyFuckingLoadingScreenArray.GetRandomElement();
            ImageWidget background = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background"));
            background.LoadImageFile(0, preel);  
        }
    }
}