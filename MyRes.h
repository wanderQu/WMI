//红
#define	 RED					RGB(255,0,0)
#define  RED2					RGB(238,0,0)
#define  RED3					RGB(205,0,0)
//橙
#define	 ORANGE					RGB(255,165,0)
#define  ORANGE2				RGB(238,154,0)
#define  ORANGE3				RGB(205,133,0)
//金
#define	 GOLD					RGB(255,215,0)
#define  GOLD2					RGB(205,201,0)
#define  GOLD3					RGB(205,173,0)
//黄
#define	 YELLOW					RGB(255,255,0)
#define  YELLOW2				RGB(238,238,0)
#define  YELLOW3				RGB(205,205,0)
//绿
#define  GREEN					RGB(0,255,0)
#define  GREEN2					RGB(0,238,0)
#define  GREEN3					RGB(0,205,0)

#define  BLACK					RGB(0,0,0)
#define  DARKGREEN				RGB(0,100,0)

#define	 LVORY					RGB(255,255,240)
#define  SNOW					RGB(250,250,250)
#define	 WHITESMOKE				RGB(245,245,245)
#define  PINK					RGB(255,192,203)
#define  GRAY					RGB(181,181,181)

#define PURPLE					RGB(155,48,255)

#define  WHITE					RGB(255,255,255)
#define  FLORALWHITE			RGB(255,250,240)
#define  OLDLACE				RGB(253,245,230)
#define	 LINEN					RGB(250,240,230) 
#define  ANTIQUEWHITE			RGB(250,235,215)
#define  PAPAYAWHIP				RGB(255,239,213)
 
#define  Blue1					RGB(0,0,255)
#define  Blue2					RGB(0,0,238)
#define  Blue3					RGB(0,0,205)
#define  Blue4					RGB(0,0,139)

#define  OliveDrab				RGB(107,142,35)

#define  Khaki1					RGB(255,246,143)
#define  Khaki2					RGB(238,230,133)
#define  Khaki3					RGB(205,198,115)
/*
 7-11:发现问题：绘图区闪烁-》使用双缓冲//依然未解决
-》

BOOL CWMIView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
		
	return CView::OnEraseBkgnd(pDC); ---》 return TRUE;

	
}
*/
