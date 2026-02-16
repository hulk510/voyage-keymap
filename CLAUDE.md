# ZSA Voyage Keymap

## Owner
- Mac ユーザー (macOS メイン、まれに Windows)
- 日本語入力あり (Ctrl+Space で IME 切替)
- QWERTY 配列 (文字キーの位置はデフォルトのまま)

## 用途
- **ターミナル**: Claude Code でのコーディングがメイン
- **Neovim**: VSCode から移行中。Vim 初心者なので自然に覚えられるキーマップが重要
- **GitButler**: 差分確認
- **Obsidian**: メモ・テキスト入力

## キーマップ方針
- レイヤーは少なめに (覚えられる範囲で)
- ハイフン、バックスラッシュなど遠いキーをアクセスしやすく
- 記号・数字も押しやすい配置に
- Vim の移動・編集を自然に覚えられる構成
- 凝りすぎない。実用性重視

## RGB / 見た目
- 虹色は NG
- 白 or 薄い紫系の落ち着いた色が好み
- レイヤーごとに色を変えて、有効キーがわかるようにしたい
- アニメーションは控えめ

## リポジトリ構成
- `X36BM/` - キーマップ本体 (keymap.c, config.h, rules.mk)
- `Dockerfile` - QMK ビルド環境
- `.github/workflows/` - GitHub Actions でファームウェアビルド
- `qmk_firmware/` - QMK サブモジュール

## ビルド手順
1. `X36BM/keymap.c` 等を編集
2. push → GitHub Actions が自動ビルド
3. Actions の Artifacts から .bin をダウンロード
4. Keymapp (ZSA デスクトップアプリ) で Flash

## 注意事項
- `fetch-and-build-layout.yml` の Action を再実行すると Oryx のデフォルトで上書きされるので実行しない
- Babel 制約なし (このリポジトリは C / QMK)
- Voyage は QMK ベースのファームウェア
