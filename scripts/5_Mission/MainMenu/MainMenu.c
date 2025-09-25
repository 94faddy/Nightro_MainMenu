modded class MainMenu extends UIScriptedMenu 
{	
	protected Widget				discord_button;
	protected Widget				twitter_button;
	protected Widget				vk_button;
	protected VideoWidget			m_Video_DF;
	protected ref Timer m_VideoCheckTimer;
	override Widget Init()
	{
		//layoutRoot = GetGame().GetWorkspace().CreateWidgets(MMpath);
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "Nightro_MainMenu/gui/MainMenu/MainMenu.layout" );
		
		m_Play						= layoutRoot.FindAnyWidget( "play" );
		m_CustomizeCharacter		= layoutRoot.FindAnyWidget( "customize_character" );
		m_SettingsButton			= layoutRoot.FindAnyWidget( "settings" );
		m_Exit						= layoutRoot.FindAnyWidget( "exit" );
		discord_button				= layoutRoot.FindAnyWidget( "discord" );
		twitter_button				= layoutRoot.FindAnyWidget( "twitter" );
		vk_button					= layoutRoot.FindAnyWidget( "VK" );

		m_Version					= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		m_Stats						= new MainMenuStats( layoutRoot.FindAnyWidget( "stats_root" ) );		
		m_Mission					= MissionMainMenu.Cast( GetGame().GetMission() );		
		m_LastFocusedButton = 		m_Play;
		//m_ScenePC					= m_Mission.GetIntroScenePC();
		
		if( m_ScenePC )
		{
			m_ScenePC.ResetIntroCamera();
		}
		
		m_PlayerName				= TextWidget.Cast( layoutRoot.FindAnyWidget("character_name") );
		
		string version;
		GetGame().GetVersion( version );
		m_Version.SetText( version );
		
		GetGame().GetUIManager().ScreenFadeOut(0);

		SetFocus( null );
		
		Refresh();
		
		GetDayZGame().GetBacklit().MainMenu_OnShow();
	
		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );
		m_Video_DF 					=  VideoWidget.Cast(layoutRoot.FindAnyWidget("DF_Video"));
		m_VideoCheckTimer = new Timer();
		StartVideo();
		return layoutRoot;
	}
	
	bool LoadVideoFileDF()
	{
		if (m_Video_DF.GetState() != VideoState.NONE)
			return true;
		
		CopyFile("Nightro_MainMenu/data/Video1.mp4", "$profile:Video1.mp4");
		CopyFile("Nightro_MainMenu/data/Video2.mp4", "$profile:Video2.mp4");
		int rnd = Math.RandomIntInclusive(0,1);
		switch (rnd)
		{
			case 0:{m_Video_DF.Load("$profile:Video1.mp4", false);break;}
			case 1:{m_Video_DF.Load("$profile:Video2.mp4", false);break;}
		}	

		return m_Video_DF.GetState() != VideoState.NONE;;
	}
	void StartVideo()
	{
		if (LoadVideoFileDF())
		{
			m_Video_DF.Play();
			m_Video_DF.Stop();
			m_Video_DF.Play();
			m_VideoCheckTimer.Run(0.1, this, "CheckVideoState", null, true);
		}
	}

	void CheckVideoState()
	{
		if (m_Video_DF.GetState() == VideoState.FINISHED)
		{
			m_Video_DF.Stop();
			m_Video_DF.Play();
		}
	}
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			if( w == m_Play )
			{
				m_LastFocusedButton = m_Play;
				g_Game.ConnectFromServerBrowser( "dayznightrosv1-hardcore.nightro.cc", 2302, "TaJin7rlYSW5V8D3vaSlzX9e2zSF685m" ); 
				return true;
			}	
			else if ( w == m_CustomizeCharacter )
			{
				OpenMenuCustomizeCharacter();
				return true;
			}
			else if ( w == discord_button )
			{
				GetGame().OpenURL(MMdiscord); 
				return true;
			}
			else if ( w == vk_button )
			{
				GetGame().OpenURL(MMvk);
				return true;
			}
			else if ( w == twitter_button )
			{
				GetGame().OpenURL(MMtwitter);
				return true;
			}
			else if ( w == m_SettingsButton )
			{
				OpenSettings();
				return true;
			}
			else if ( w == m_Exit )
			{
				Exit();
				return true;
			}
		}
		return false;
	}

	void OnChangeCharacter(bool create_character = true)
	{
		if ( m_ScenePC && m_ScenePC.GetIntroCharacter() )
		{
			int charID = m_ScenePC.GetIntroCharacter().GetCharacterID();
			if (create_character)
			{
				m_ScenePC.GetIntroCharacter().CreateNewCharacterById( charID );
			}
			m_PlayerName.SetText( "#c_welcome" + " " + m_ScenePC.GetIntroCharacter().GetCharacterNameById( charID ) );
			
			Widget w = m_CustomizeCharacter.FindAnyWidget(m_CustomizeCharacter.GetName() + "_label");
			
			if ( w )
			{
				TextWidget text = TextWidget.Cast( w );
				
				if( m_ScenePC.GetIntroCharacter().IsDefaultCharacter() )
				{
					text.SetText("#layout_main_menu_customize_char");
				}
				else
				{
					text.SetText("#layout_main_menu_rename");
				}
			}
			if (m_ScenePC.GetIntroCharacter().GetCharacterObj() )
			{
				if ( m_ScenePC.GetIntroCharacter().GetCharacterObj().IsMale() )
					m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Male);
				else
					m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Female);
			}
			
			//update character stats
			m_Stats.UpdateStats();
		}
	}
	override void LoadMods()
	{
		return;
	}
	
	override void Play()
	{
		return;
	}
}