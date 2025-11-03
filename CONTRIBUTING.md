# 🤝 Contributing to FLAC Media Converter
感謝你有興趣參與本專案！ 以下是一些簡單的指引，幫助你順利貢獻。

---

## 📌 如何參與
* 回報問題（Issues）
* 提交新功能或修正（Pull Requests）
* 改善文件（Docs）
* 測試與回饋（Testing & Feedback）

---

## 🐛 回報問題 (Issues)
* 請先搜尋是否已有相同問題
* 提供：
	* 作業系統與版本
	* 軟體版本
	* 問題描述與重現步驟
	* 預期行為與實際行為

---

## 🌱 開發流程
1. Fork 專案
2. 建立分支：
```
git checkout -b feature/your-feature
```
3. 提交修改：
```
git commit -m "Add: 說明修改內容"
```
4. Push 到你的分支：
```
git push origin feature/your-feature
```
5. 發送 Pull Request

---

## 📝 程式碼規範
* 使用 C++17 / Qt 6
* 遵循 clang-format 設定
* 命名規則：
	* 類別：PascalCase
	* 函式：camelCase
	* 變數：camelCase
	* 常數：ALL_CAPS
* 每個功能需附上基本測試（tests/）

---

## 🌐 文件與翻譯
* 文件放在 docs/
* 翻譯檔放在 i18n/
* 新增語言時，請更新 README 與設定選項

---

## ✅ Pull Request 檢查清單
- [ ] 程式碼可編譯並通過測試
- [ ] 文件已更新（若有需要）
- [ ] 遵循程式碼規範
- [ ] Commit 訊息清楚描述修改內容

---

## 📜 授權
提交的程式碼將依照本專案的 [LICENSE](LICENSE)條款釋出。
