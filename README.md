# FLAC Media Converter

輕鬆將任何音訊檔案轉換為 FLAC 格式，支援跨平台、跨作業系統，並提供多語系介面與自訂設定檔功能。

---

## ✨ 功能特色

* 🎵 音訊轉換：透過 ffmpeg 將來源檔案轉換為 FLAC
* 📂 檔案匯入：支援檔案對話框與拖拉匯入
* ⚙️ 自訂設定檔：內建 Profiles + JSON 格式自訂 Profiles
* 🌐 多語系支援：繁體中文 / 英文 / 日文
* 📊 即時進度：單檔與整體進度條、檔案清單狀態
* 🛠 效能測試工具：轉換速度與資源使用分析
* 🖥 跨平台：Windows / macOS(預定未來支援) / Linux

---

## 📦 安裝方式

### Windows

* 下載 Release 中的安裝檔（已附帶 ffmpeg/ffprobe）
* 解壓縮或執行安裝程式即可使用

### macOS(預定未來支援)

* 下載 .dmg 檔，拖曳至 Applications
* ffmpeg/ffprobe 可隨附或透過 Homebrew 安裝

### Linux

* 使用 AppImage 或 .deb/.rpm 套件
* 需先安裝 ffmpeg 與 ffprobe

---

## 🚀 使用方式

1. 開啟程式
2. 匯入音訊檔案（對話框或拖拉）
3. 選擇 Profile 與輸出目錄
4. 點擊「開始轉換」
5. 查看進度對話框，完成後會顯示提示訊息

---

## 📂 專案結構

```
src/        # 主要程式碼
profiles/   # 內建 Profiles JSON
i18n/       # 語系檔 (.ts/.qm)
config/     # 預設設定檔
tests/      # 測試程式
packaging/  # 打包腳本
docs/       # 文件與設計
```

---

## 🛠 開發 Roadmap

* v0.1 – MVP 核心功能：檔案匯入、Profile 載入、轉換與進度
* v0.2 – Profile Manager & 設定：Profile CRUD、設定對話框、初始精靈
* v0.3 – 多語系 & 附加功能：語言切換、效能測試、Log/CUE
* v0.4 – 跨平台打包：Windows/macOS/Linux 打包
* v1.0 – 穩定版：完整測試、文件、正式發佈

---

## 🤝 貢獻方式

1. Fork 專案
2. 建立 feature branch (git checkout -b feature/xxx)
3. 提交修改 (git commit -m "Add xxx")
4. Push 到分支 (git push origin feature/xxx)
5. 發送 Pull Request

---

## 📜 授權

本專案採用 MIT License，並依照 [CC BY-NC-SA 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/) 授權條款釋出。
