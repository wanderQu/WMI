#include "StdAfx.h"/*
//PROCURMENT采购

	CString	ProcurmentTable[] = {"采购订单","采购日期","商品名称","商品数量","商品单价","预计到货时间"}; //采购订单

	CString ProcurmentDetail[] = {"采购编号","采购日期","商品名称","商品数量","商品单价","预计到货时间","采购状态","付款状态"};//采购明细查询 

	CString ProcurmentTrack[] = {"采购编号","商品名称","采购日期","采购订单编号","供应商","采购状态",
						"数量","单价","采购额","未入库数量","预计到货时间","最后入库时间"};//采购跟踪

	CString ProcurmentReturn[] = {"采购编号","退货时间","商品名称","商品数量","商品原订购数量","商品金额","退货原因"};//退货

	CString ProcurmentAI[] = {"商品","在库量","最低库存","建议采购量","采购在定量"};//智能订购



//DISTRIBUTION配送

	CString DistributionTable[] = {"配送编号","配送日期","商品名称","商品数量","商品单价","预计交货时间"}; //配送表

	CString DistributionDetail[] = {"配送编号","配送日期","商品名称","商品数量","商品单价","预计交货时间","配送状态","收款状态"};//配送明细

	CString DistributionTrack[] = {"配送编号","商品名称","配送日期","配送订单编号","供应商","配送状态",
						"数量","单价","采购额","未出库数量","预计交货时间","最后出库时间"};//采购跟踪


//WAREHOUSE仓库

	CString  DistributionTransfer[] = {"单据编号","单据日期","商品编号","数量","规格","单位","调出仓库","调入仓库","制单人","备注"}; //调拨

	CString  DistributionPutIn[] = {"单据编号","单据日期","仓库","商品编号","商品","数量","金额","供应商","制单人","备注","打印次数"};//入库
	
	CString  DistributionPutOut[] = {"单据编号","单据日期","仓库","商品编号","商品","数量","金额","客户","制单人","备注","打印次数"};//出库
	
	CString  DistributionInventory[] = {"单据编号","单据日期","仓库","商品编号","商品","规格","单位","数量","制单人","备注"};//盘点

	CString  DistributionAdjust[] = {"单据编号","单据日期","仓库","商品编号","商品","数量","制单人","备注"};//调整
	
	CString  DistributionState[] = {"日期","仓库","商品编号","商品","规格","单位","数量"};//状态


//MANAGEMENT管理

	CString ManageCustomer[] = {"客户编号","客户类别","客户名称","联系人","联系方式","账户"}; //客户管理

	CString ManageSupplier[] = {"供应商编号","供应商类别","供应商名称","联系人","联系方式","账户"};//供应商管理

	CString ManageGoods[] = {"商品编号","商品类别","商品","仓库","商品数量","单价"};//商品管理

	CString ManageWareHouse[] = {"仓库编号","仓库名称","仓库状态"};//仓库管理

	CString ManageAddress[] = {"配送地址","联系人","联系方式","邮政编码"};//配送地址管理



//DATA资料

	CString DataReceipt[] = {"单据编号","客户","资金类别","收款金额","优惠金额","备注"};//收款单
	
	CString DataPayment[] = {"单据编号","供应商","资金类别","付款金额","优惠金额","备注"};//付款单

	CString DataVerification[] = {"单据编号","核销单据","已核销金额","未核销金额","本次核销金额","资金类别","备注"};//核销单

	CString DataOtherIncome[] = {"单据编号","资金类别","金额","备注"};//其他收入单

	CString DataOtherSpend[] = {"单据编号","资金类别","金额","备注"};//其他支出单

	CString DataTransfer[] = {"转出账户","转入账户","金额","备注"};//转账单



//REPORT报表

	CString ReportSpendReport[] = {"单据编号","资金类别","金额","备注"};

	CString ReportPayable[] = {"单据编号","供应商","应付账款金额","备注"};

	CString ReportReceivable[] = {"单据编号","客户","应收账款金额","备注"};
	
	CString ReportCustomer[] = {"单据编号","客户","来往交易","已收金额","应付账款余额","备注"};
	
	CString ReportSupplier[] = {"单据编号","供应商","来往交易","已付金额","应付账款余额","备注"};
	
	CString ReportOtherIncome[] = {"单据编号","资金类别","金额","备注"};
	
	CString ReportProfits[] = {"编制日期","项目","行次","金额"};
*/