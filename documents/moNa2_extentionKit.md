# moNa2拡張キットの使い方

- 本ドキュメントではトラックパッドをmoNa2へ組み込む手順について解説します。
- 本ドキュメントではmoNa2右手側のトラックボールは残しつつ、左手側のロータリーエンコーダーをトラックパッドに換装する方法を例示します。
- 本ドキュメントではZMKのビルド手順など、基本的な解説は省略しています。

## moNa2のロータリーエンコーダーを取り外す

<img width="1024" height="656" alt="2026-03-28_12h59_17" src="https://github.com/user-attachments/assets/dfb5ea6e-5524-4737-b1b7-7d198c763d27" />


## マイコンとブレークアウトボードを配線図に従って繋ぐ

<img width="1061" height="1279" alt="2026-03-28_13h04_34" src="https://github.com/user-attachments/assets/cf80116f-213e-45b1-8a8f-b9e2cc02021b" />

<img width="1364" height="768" alt="2026-03-28_13h05_04" src="https://github.com/user-attachments/assets/4325f1ed-6ac9-4a4c-bd48-980a10305c29" />

## ブレークアウトボードを適当な両面テープ等でマイコンに固定する

<img width="1546" height="612" alt="2026-03-28_13h06_03" src="https://github.com/user-attachments/assets/5b2d5b46-96d8-4b8f-9ca0-415f64dc7259" />


## アダプターパーツ（3DP製）を使ってトラックパッドをmoNa2に固定する

<img width="2760" height="1005" alt="2026-03-28_13h09_22" src="https://github.com/user-attachments/assets/169c2c7a-a760-433d-b83a-7343e776ee6d" />

<img width="1547" height="789" alt="2026-03-28_13h09_55" src="https://github.com/user-attachments/assets/4253c42e-0e73-4162-aba6-892b91022766" />


## ファームウェアをセットアップする

- ShiniNet作成の[moNa2ファームウェアのフォーク](https://github.com/ShiniNet/zmk-config-moNa2-v2_TP/actions/runs/23678787056)から最新のUF2ファイルを取得する
- moNa2へファームウェアを投入する。

> [!TIP]
> - 自前のmoN2フォークへ組み込みたい場合、[コミットログ](https://github.com/ShiniNet/zmk-config-moNa2-v2_TP/commit/7e83a23ea202d5694ea33503b81cd67133515d6f)を参考に変更を取り込む。

## 動作確認
